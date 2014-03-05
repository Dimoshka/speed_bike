// 5110lcd操作库
#include <avr/io.h>
#include <util/delay.h>
#include "nokia5110.h"


static void nokia5110_send1byte(char cData, char data);
static void nokia5110_write_char(unsigned char c);

/**
 * Переместить курсор, и в этой строке начинает печать, он будет автоматически перенесен
 * @param y стартовая строка
 * @param x стартовый столбец
 * @param str текстовая строка
 */
void nokia5110_mvprint(unsigned char y, unsigned char x, char *str)
{
	nokia5110_mv(y, x*6);     //以一个字符为单位
	nokia5110_print(str);
}
/**
 * Записать строку
 * @param string
 */
void nokia5110_print(char * string)
{
	while (*string!='\0') {
		nokia5110_write_char(*string++);
	}
}
/**
 * Написать характера, начиная с ascii32 быть отображаемых символов,
 * @param c
 */
static void nokia5110_write_char(unsigned char c)
{
	unsigned char line;
	c -= 32;
	for (line = 0; line<6; line++) {
		nokia5110_send1byte(NOKIA5110_DATA, font6x8[c][line]);
	}

}
/**
 * Отправить байта
 * @param bdata 数据还是命令
 * @param cData 发送的那个字节
 */
static void nokia5110_send1byte(char bdata, char cData)
{
	if (bdata) {     //Набор D / C выход
		PORT_DC |= _BV(PIN_DC);
	} else {     //command От низкого до операции команды
		PORT_DC &= ~_BV(PIN_DC);
	}
	SPI_MasterTransmit(cData);
}
/**
 * инициализация
 */
void nokia5110_init(void)
{
	//инициализация SPI
	SPI_MasterInit();
	DDR_DC |= _BV(PIN_DC);     //设置D/C输出
	DDR_RST |= _BV(PIN_RST);     //设置rst输出
	//Импульс сброса
	PORT_RST &= ~_BV(PIN_RST);
	_delay_ms(2);
	PORT_RST |= _BV(PIN_RST);
	//Используя расширенный набор команд
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_EX_instruction);

	// 1: Установить VOP b8 = 1, B [7-0] => Vop [7-0]
	nokia5110_send1byte(NOKIA5110_CMD, 0xc8);     //偏置电压
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_SET_Vop|0x48);     //напряжение смещения
	// 2: температура
	nokia5110_send1byte(NOKIA5110_CMD, 0b00000111);     //коррекция температуры
	// 3: степень смешивания
	nokia5110_send1byte(NOKIA5110_CMD, 0x10);     //混合度 1:48
	//Настроить с помощью базового набора инструкций
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_BASE_instruction);
	//Устанавливается в обычный режим
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	nokia5110_clear();
}

/**
 * Переместить курсор в указанное место
 * @param x [0,83] Первые несколько столбцов
 * @param y [0,5] Первые несколько строк
 */
void nokia5110_mv(unsigned char y, unsigned char x)
{
	nokia5110_send1byte(NOKIA5110_CMD, x|NOKIA5110_SET_RAMADDR_X);     //X
	nokia5110_send1byte(NOKIA5110_CMD, y|NOKIA5110_SET_RAMADDR_Y);     //Y
}
/**
 * Очистить экран
 */
void nokia5110_clear(void)
{
	int i;
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	for (i = 0; i<504; i++) {
		nokia5110_send1byte(NOKIA5110_DATA, 0);
	}
	nokia5110_mv(0, 0);
}

/**
 * Простая точка картины
 * @param y является строка из восьми рядов пикселей
 * @param x 1 пиксель
 */
void nokia5110_drawpix(unsigned char y,unsigned char x)
{
	nokia5110_send1byte(NOKIA5110_CMD, x|NOKIA5110_SET_RAMADDR_X);     //X
	nokia5110_send1byte(NOKIA5110_CMD, y|NOKIA5110_SET_RAMADDR_Y);     //Y
	nokia5110_send1byte(NOKIA5110_DATA, 0b00000001);
}
