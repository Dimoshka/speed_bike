#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "spi.h"
void SPI_MasterInit(void)
{
	/* Установка MOSI и SCK выход, все остальные вход */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<SS);
	/* Enable SPI, мастер, установить тактовую частоту fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}
void SPI_MasterTransmit(char cData)
{
	/* Инициировать процесс передачи данных */
	SPDR = cData;
	/* Дождитесь полной передачи */
	while (!(SPSR &(1<<SPIF))) {
		;
	}
}
