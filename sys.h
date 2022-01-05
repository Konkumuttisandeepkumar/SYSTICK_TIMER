//This is sys.h file

#define MCU_CLK 32000000   //Internal clock speed for INFINEON XMC 4400 is 32MHZ 
#define ms 		32000
#define us 		32

#define MCU_CLK 16000000   //Internal clock speed for STM32F401RBT6 is 16MHZ 
#define ms 		16000
#define us 		16



extern void init_systick_timer(void);
extern void delay_ms(uint16_t delay);
extern void delay_us(uint16_t delay);
