#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <pwm.h>

volatile int up = 0;
void setupInterrupt(){
	cli();
	DDRB &= ~(1<<DDB2); // Bank B Data Direction: PB2 is input
	//PORTB |= 0x04; // Bank B Output/Pullup: PB2 is HIGH
	//PUEB |= 0x00; // Bank B Pull Up Enable: PB2 is pulled up
	
	//PCICR |= 0x0; // Pin Change Interrupt Control Reg: enable pin change interrupts
	//PCMSK = 0x0; // Pin Change Mask Reg: No PCINTn interrupts enabled
	EIMSK |= 0x01; // Ext. Int. Mask Reg: Enable INT0
	EICRA = 0x01; // Ext. Int. Control Reg: Any logical change in INT0 will trigger

	////set_sleep_mode();
	//SMCR |= 0x010 << 1;
	
	//DDRB |= 0x01;
	//PORTB &= ~0x01;
	sei();
}

ISR(INT0_vect){
	if(PINB & 0x04){
		up = 2;
		//while(PWM)
		//	PWM -= 0x10;
		//sleep_enable(); // SMCR |= 0x01 // Sleep Mode Control Register: enable sleep
		//sei();
		//sleep_cpu();
		//sleep_disable();
	}else{
		up = 1;
		//while(PWM != PWM_TOP)
		//	PWM += 0x01;
	}
}
