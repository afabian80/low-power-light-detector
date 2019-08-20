#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= (1 << 3);

	while(1) {
		PORTB = (1 << 3);
		_delay_ms(200);
		PORTB = 0;
		_delay_ms(700);
	}
	return 0;
}
