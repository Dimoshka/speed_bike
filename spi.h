#ifndef _SPI_H_
#define _SPI_H_

#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_SCK PB5
#define SS PB2

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
#endif
