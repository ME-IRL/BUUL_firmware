#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <pwm.h>

volatile int up = 0;
void setupInterrupt(){
	cli();
	DDRB &= ~(1<<DDB2); // Bank B Data Direction: PB2 is input
	EIMSK |= 0x01; // Ext. Int. Mask Reg: Enable INT0
	EICRA = 0x01; // Ext. Int. Control Reg: Any logical change in INT0 will trigger

	////set_sleep_mode();
	//SMCR |= 0x010 << 1;
	sei();
}

ISR(INT0_vect){
	if(PINB & 0x04){
		PWM = 0x0;
	}else{
		PWM = PWM_TOP;
	}
}
