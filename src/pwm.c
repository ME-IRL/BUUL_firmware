#include <avr/io.h>
#include <avr/interrupt.h>
#include <pwm.h>

void setupPWM(){
	DDRB |= 0x01; // Bank B Data Direction: PB0 is output

	TCCR0A |= 2<<WGM00; // Fast PWM Mode
	TCCR0B |= 3<<WGM02; // With TOP value @ ICR0
	TCCR0A |= 3<<COM0A0; // Non-inverting mode
	TCCR0B |= 1<<CS00; // No prescaling (from system clock)

	cli(); // should be done to write 16-bit values below
	ICR0 = PWM_MAX; // Max precision of 16-bits
	PWM = 0x0000; // Initialize PWM to 0% Duty Cycle
	sei(); // re-enable interrupts
}
