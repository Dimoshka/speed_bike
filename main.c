#include <avr/io.h>
#include <util/delay.h>
#include "nokia5110.h"
#include "watch.h"

int main(void) {
	nokia5110_init();
	watch_init();

	nokia5110_mvprint(3, 2, "DIMOSHKA");
	_delay_ms(100);
	nokia5110_mvprint(5, 1, "loading...");
	_delay_ms(1000);

	while (1) {
		_delay_ms(1000);
		nokia5110_clear();
		nokia5110_mvprint(0, 0, get_watch());
	}
	return 0;
}
