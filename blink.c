/*
  Blink an LED with an Attiny85 chip (PB3 pin).
  Go to sleep between flashes.
  External hardware is only an LED with its 220 Ohm resistor.
  Measured power consumption is ~ 6.8 uA at 5 volts
  (with the LED disconnected).
*/

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <util/delay.h>

int main(void) {
	DDRB |= _BV(PB3);		// LED on PB3
	ADCSRA &= ~_BV(ADEN);	// disable ADC to save power
	wdt_enable(WDTO_1S);	// enable watchdog timer (1s)
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);	// lowest power state

	while(1) {
		PORTB = _BV(PB3);	// turn on LED for a short time
		_delay_ms(20);
		PORTB = 0;
		sleep_mode();		// sleep till WDT wakes the CPU up
	}
	return 0;
}
