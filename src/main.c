#include <util/delay.h>
#include <avr/io.h>
#include <pwm.h>
#include <interrupt.h>

static inline void setupClock(){
	CCP = 0xD8; // Change Config Reg: protected registers can be changed in next 4 cycles
	CLKPSR = 0x00; // Clock Prescaler Register: set clock division to 1
}

static inline void setup(){
	setupClock();
	setupPWM();
	setupInterrupt();
}

int main(){
	setup();
	while(1);
}
