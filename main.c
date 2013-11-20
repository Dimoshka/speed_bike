#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"

struct Timer {

	unsigned int tic;
	unsigned int seconds;
	unsigned int minutes;
	unsigned int hours;
	unsigned int days;
	unsigned int month;
	unsigned int year;
};
unsigned int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
unsigned int DaysInMonth;
char *time_str;

struct Timer timer = { 0, 0, 0, 0, 1, 1, 1970 };
int isLeapYear(int month) {
	if (month % 4) {
		return 1;
	} else {
		return 0;
	}
}
;

ISR(TIMER2_OVF_vect) {
	timer.tic++;

	if (timer.tic % 2 == 0) {

		//Секунда
		timer.seconds++;
		if (timer.seconds > 59) {

			//Минута
			timer.seconds = 0;
			timer.minutes++;

			if (timer.minutes > 59) {

				//Час
				timer.minutes = 0;
				timer.hours++;

				if (timer.hours > 23) {

					//День
					timer.hours = 0;
					timer.days++;

					//Количество дней в месяце
					DaysInMonth = Month[timer.month - 1];

					if (timer.month == 2 && isLeapYear(timer.year) == 1) {
						//Если высокосный год - +1 день
						DaysInMonth++;
					}

					if (timer.days > DaysInMonth) {
						//Месяца
						timer.days = 1;
						timer.month++;
						if (timer.month > 12) {
							//Год
							timer.month = 1;
							timer.year++;

						}
					}
				}
			}
		}
		//PORTB |= (1 << PB0);
		sprintf(time_str, "%h:%i:%s %y-%m-%d", timer.hours, timer.minutes,
				timer.seconds, timer.year, timer.month, timer.days);
		nokia5110_clear();
		nokia5110_mvprint(0, 0, time_str);
		//} else {
		//PORTB &= ~(1 << PB0);
	}
}

int main(void) {
	nokia5110_init();
	//PORTB = (0 << PB0); //Записываем 0 для отключения питания на выходе при старте.
	//DDRB = (1 << DDB0); //Выводы 1 и 2 порта D - выходы
	ASSR = 0x08;
	TCCR2 = 0x05;
	TCNT2 = 0x00;
	OCR2 = 0x00;
	TIMSK = 0b01000000;
	sei();

	nokia5110_mvprint(3, 2, "DIMOSHKA");
	_delay_ms(100);
	nokia5110_mvprint(5, 1, "loading...");
	_delay_ms(1000);

	while (1) {

	}
}
