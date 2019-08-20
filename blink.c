/*
  Blink an LED on an Attiny85 (PB3 pin).
  Go to sleep between flashes.
  External hardware is only an LED with its 220 Ohm resistor.
  Measured power consumption is ~ 6.8 uA at 5 volts (with the LED disconnected).
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

int main(void) {
	DDRB |= (1 << 3);		// led on PB3
	ADCSRA  &= ~_BV(ADEN);  // disable ADC to save power
	wdt_enable(WDTO_1S);	// reset every second
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);	// lowest power state (6.8 uA)

	while(1) {
		PORTB = (1 << 3);	// turn on led for a short time
		_delay_ms(20);
		PORTB = 0;
		sleep_mode();		// low power sleep between led flashes
	}
	return 0;
}
