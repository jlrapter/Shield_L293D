
#define		DIR_LATCH	PB4
#define		DIR_SER		PB0
#define		DIR_EN		PD7
#define		DIR_CLK		PD4

#define		DIR_LATCH_DDR	DDRB
#define		DIR_SER_DDR		DDRB
#define		DIR_EN_DDR		DDRD
#define		DIR_CLK_DDR		DDRD

#define		DIR_LATCH_PORT	PORTB
#define		DIR_SER_PORT	PORTB
#define		DIR_EN_PORT		PORTD
#define		DIR_CLK_PORT	PORTD

#define		PWM0A_M4	PD6
#define		PWM0B_M3	PD5
#define		PWM2A_M1	PB3
#define		PWM2B_M2	PD3

#define		PWM0A_M4_DDR	DDRD
#define		PWM0B_M3_DDR	DDRD
#define		PWM2A_M1_DDR	DDRB
#define		PWM2B_M2_DDR	DDRD

#define		PWM0A_M4_PORT	PORTD
#define		PWM0B_M3_PORT	PORTD
#define		PWM2A_M1_PORT	PORTB
#define		PWM2B_M2_PORT	PORTD

#define		M3A		7
#define		M2A		6
#define		M1A		5
#define		M1B		4
#define		M2B		3
#define		M4A		2
#define		M3B		1
#define		M4B		0

#define		BYTE_SIZE 8
#define		MAX_DUTY	255

#define		ENABLE_M1	1
#define		ENABLE_M2	1
#define		ENABLE_M3	1
#define		ENABLE_M4	1
#define		ENABLE_MA	1
#define		ENABLE_MB	1

#define		DISABLE_M1	0
#define		DISABLE_M2	0
#define		DISABLE_M3	0
#define		DISABLE_M4	0
#define		DISABLE_MA	0
#define		DISABLE_MB	0


void L293D_Shield_Start (uint8_t enable_M1, uint8_t enable_M2, uint8_t enable_M3, uint8_t enable_M4,
uint8_t enable_MA, uint8_t enable_MB);

void L293D_Enable_Shield(void);
void L293D_Disable_Shield(void);

void L293D_Set_Motors(uint8_t Ser_Val);

void L293D_Stop_Motors(void);

void L293D_Set_M1_DIR_R(void);
void L293D_Set_M1_DIR_L(void);
void L293D_Set_M2_DIR_R(void);
void L293D_Set_M2_DIR_L(void);
void L293D_Set_M3_DIR_R(void);
void L293D_Set_M3_DIR_L(void);
void L293D_Set_M4_DIR_R(void);
void L293D_Set_M4_DIR_L(void);
void L293D_Set_MA_DIR_R(void);
void L293D_Set_MA_DIR_L(void);
void L293D_Set_MB_DIR_R(void);
void L293D_Set_MB_DIR_L(void);


void L293D_Set_Duty_M1(double duty_percentage);
void L293D_Set_Duty_M2(double duty_percentage);
void L293D_Set_Duty_M3(double duty_percentage);
void L293D_Set_Duty_M4(double duty_percentage);
void L293D_Set_Duty_MA(double duty_percentage);
void L293D_Set_Duty_MB(double duty_percentage);


