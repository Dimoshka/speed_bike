#ifndef _NOKIA_5110_H_
#define _NOKIA_5110_H_
#include "ascii.h" //набор символов
#include "spi.h" //spi операции
#define NOKIA5110_DATA (1) //Данные
#define NOKIA5110_CMD (0) //Или команда
#define NOKIA5110_SET_RAMADDR_Y (0b01000000)
#define NOKIA5110_SET_RAMADDR_X (0b10000000)
#define NOKIA5100_SET_Vop 	(0b10000000)
#define NOKIA5100_BASE_instruction 	(0x20) //Основной комплект программ
#define NOKIA5100_EX_instruction 	(0x21) //Расширенные инструкций
#define NOKIA5110_NOMAL_MODE 	(0x0c) //Нормальный режим

// LCD				ATmage8

// 1 - RST:	PB2
// 2 - CE: Gnd
// 3 - DC: PB1
// 4 - Din: PB3 (MOSI/OC2)
// 5 - Clk: (SCK) PB5
// 6 - Vcc: источник питания
// 7 - Gnd:земля
// 8 - BL: Gnd

#define DDR_DC DDRB
#define PORT_DC PORTB
#define PIN_DC PB1
#define DDR_RST DDRB
#define PORT_RST PORTB
#define PIN_RST PB2

extern void nokia5110_init(void);
extern void nokia5110_clear(void);
extern void nokia5110_mvprint(unsigned char y, unsigned char x, char *str);
extern void nokia5110_mv(unsigned char y, unsigned char x);
extern void nokia5110_print(char * string);
extern void nokia5110_drawpix(unsigned char y,unsigned char x);
#endif
