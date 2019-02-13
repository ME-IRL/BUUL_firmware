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
	
	//int up = 0;
	int count = 0;
	while(1){
//		if(up == 2){ // DOWN
//			PWM -= 0x1;
//			if(PWM == 0)
//				up = 0;
//		}else if(up){ // UP
//			PWM += 0x1;
//			if(PWM == PWM_TOP)
//				up = 0;
//		}
//	}

		if(up == 1){
			if(count++ % 512){
				PWM += 0x01;
			}
			if(PWM == PWM_TOP){
				up = 0;
				count = 0;
			}
		}else if(up == 2){
			if(count++ % 64){
				PWM -= 0x02;
				if(PWM % 2)
					PWM -= 0x01;
			}
			if(PWM == 0){
				up = 0;
				count = 0;
			}
		}
	}
}
