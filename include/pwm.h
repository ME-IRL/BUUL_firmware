#ifndef __PWM_H
#define __PWM_H

//#define PWM_MAX (0x00FF>>1)
//#define PWM_TOP (0x00DD>>1)

#define PWM_MAX 0x007F
#define PWM_TOP 0b01111000

#define PWM OCR0A

void setupPWM();

#endif
