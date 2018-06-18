#define		F_CPU		16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "L293D_Shield.h"
#include "pwm.h"

uint8_t L293D_Actual_Ser = 0;

pwm_out_t pwm_M1;
pwm_out_t pwm_M2;
pwm_out_t pwm_M3;
pwm_out_t pwm_M4;


void L293D_Shield_Start (uint8_t enable_M1, uint8_t enable_M2, uint8_t enable_M3, uint8_t enable_M4,
						uint8_t enable_MA, uint8_t enable_MB)
{
	DIR_LATCH_DDR |= (1<<DIR_LATCH);
	DIR_SER_DDR |= (1<<DIR_SER);
	DIR_EN_DDR |= (1<<DIR_EN);
	DIR_CLK_DDR |= (1<<DIR_CLK);		
	
	L293D_Disable_Shield();
	L293D_Stop_Motors();
	
	if (enable_M4) // Initialize PWM0A Motor 4 
		pwm_init(&pwm_M4, &PWM0A_M4_DDR, PWM0A_M4, PWM_TIMER0, PWM_CHAN_A, 0, PRESCALER_T0_64);
	if (enable_M3) // Initialize PWM0B Motor 3
		pwm_init(&pwm_M3, &PWM0B_M3_DDR, PWM0B_M3, PWM_TIMER0, PWM_CHAN_B, 0, PRESCALER_T0_64);
	if (enable_M2) // Initialize PWM2B Motor 2
		pwm_init(&pwm_M2, &PWM2B_M2_DDR, PWM2B_M2, PWM_TIMER2, PWM_CHAN_B, 0, PRESCALER_T2_64);
	if (enable_M1) // Initialize PWM2A Motor 1
		pwm_init(&pwm_M1, &PWM2A_M1_DDR, PWM2A_M1, PWM_TIMER2, PWM_CHAN_A, 0, PRESCALER_T2_64);
	if (enable_MA)
	{
		pwm_init(&pwm_M1, &PWM2A_M1_DDR, PWM2A_M1, PWM_TIMER2, PWM_CHAN_A, 0, PRESCALER_T2_64);
		pwm_init(&pwm_M2, &PWM2B_M2_DDR, PWM2B_M2, PWM_TIMER2, PWM_CHAN_B, 0, PRESCALER_T2_64);
	}
	if (enable_MB)
	{
		pwm_init(&pwm_M3, &PWM0B_M3_DDR, PWM0B_M3, PWM_TIMER0, PWM_CHAN_B, 0, PRESCALER_T0_64);
		pwm_init(&pwm_M4, &PWM0A_M4_DDR, PWM0A_M4, PWM_TIMER0, PWM_CHAN_A, 0, PRESCALER_T0_64);
	}
	
	L293D_Enable_Shield();
	
	return;
}

void L293D_Enable_Shield(void)
{
	DIR_EN_PORT &= ~ (1<<DIR_EN);
	return;
}

void L293D_Disable_Shield(void)
{
	DIR_EN_PORT |= (1<<DIR_EN);
	return;
}

void L293D_Set_Motors(uint8_t Ser_Val)
{
	uint8_t i;
	
	for (i=0; i<BYTE_SIZE;i++)
	{
		if ((Ser_Val & (1<<i)) == (1<<i))
			DIR_SER_PORT |= (1<<DIR_SER);
		else
			DIR_SER_PORT &= ~(1<<DIR_SER);
		
		DIR_CLK_PORT |= (1<<DIR_CLK);	//Set Serial Clock
		_delay_us(5);
		DIR_CLK_PORT &= ~(1<<DIR_CLK);  //Clear Serial Clock
	}
	DIR_LATCH_PORT |= (1<<DIR_LATCH);	//Set Parallel Clock
	_delay_us(5);
	DIR_LATCH_PORT &= ~(1<<DIR_LATCH);	//Clear Parallel Clock
	
	return;
}

void L293D_Stop_Motors(void)
{	
	L293D_Actual_Ser = 0;
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}


void L293D_Set_M1_DIR_R(void)
{	
	L293D_Actual_Ser |= (1<<M1A);
	L293D_Actual_Ser &= ~(1<<M1B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M1_DIR_L(void)
{	
	L293D_Actual_Ser &= ~(1<<M1A);
	L293D_Actual_Ser |= (1<<M1B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M2_DIR_R(void)
{
	L293D_Actual_Ser |= (1<<M2A);
	L293D_Actual_Ser &= ~(1<<M2B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M2_DIR_L(void)
{
	L293D_Actual_Ser &= ~(1<<M2A);
	L293D_Actual_Ser |= (1<<M2B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M3_DIR_R(void)
{
	L293D_Actual_Ser |= (1<<M3A);
	L293D_Actual_Ser &= ~(1<<M3B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M3_DIR_L(void)
{
	L293D_Actual_Ser &= ~(1<<M3A);
	L293D_Actual_Ser |= (1<<M3B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M4_DIR_R(void)
{
	L293D_Actual_Ser |= (1<<M4A);
	L293D_Actual_Ser &= ~(1<<M4B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_M4_DIR_L(void)
{
	L293D_Actual_Ser &= ~(1<<M4A);
	L293D_Actual_Ser |= (1<<M4B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_MA_DIR_R(void)
{
	L293D_Actual_Ser |= (1<<M1A);
	L293D_Actual_Ser &= ~(1<<M1B);
	L293D_Actual_Ser |= (1<<M2A);
	L293D_Actual_Ser &= ~(1<<M2B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_MA_DIR_L(void)
{
	L293D_Actual_Ser &= ~(1<<M1A);
	L293D_Actual_Ser |= (1<<M1B);
	L293D_Actual_Ser &= ~(1<<M2A);
	L293D_Actual_Ser |= (1<<M2B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_MB_DIR_R(void)
{
	L293D_Actual_Ser |= (1<<M3A);
	L293D_Actual_Ser &= ~(1<<M3B);
	L293D_Actual_Ser |= (1<<M4A);
	L293D_Actual_Ser &= ~(1<<M4B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_MB_DIR_L(void)
{
	L293D_Actual_Ser &= ~(1<<M3A);
	L293D_Actual_Ser |= (1<<M3B);
	L293D_Actual_Ser &= ~(1<<M4A);
	L293D_Actual_Ser |= (1<<M4B);
	L293D_Set_Motors(L293D_Actual_Ser);
	return;
}

void L293D_Set_Duty_M1(double duty_percentage)
{
	pwm_set_duty(&pwm_M1, (uint8_t)((duty_percentage * MAX_DUTY)/100.0));
	return;
}

void L293D_Set_Duty_M2(double duty_percentage)
{
	pwm_set_duty(&pwm_M2, (uint8_t)((duty_percentage * MAX_DUTY)/100.0));
	return;
}

void L293D_Set_Duty_M3(double duty_percentage)
{
	pwm_set_duty(&pwm_M3, (uint8_t)((duty_percentage * MAX_DUTY)/100.0));
	return;
}

void L293D_Set_Duty_M4(double duty_percentage)
{
	pwm_set_duty(&pwm_M4, (uint8_t)((duty_percentage * MAX_DUTY)/100.0));
	return;
}

void L293D_Set_Duty_MA(double duty_percentage)
{
	uint8_t pwm_val = (uint8_t)((duty_percentage * MAX_DUTY)/100.0);
	
	pwm_set_duty(&pwm_M1, pwm_val);
	pwm_set_duty(&pwm_M2, pwm_val);
	return;
}

void L293D_Set_Duty_MB(double duty_percentage)
{
	uint8_t pwm_val = (uint8_t)((duty_percentage * MAX_DUTY)/100.0);
	
	pwm_set_duty(&pwm_M3, pwm_val);
	pwm_set_duty(&pwm_M4, pwm_val);
	return;
}