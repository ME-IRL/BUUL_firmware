#ifndef __PWM_H
#define __PWM_H

#define PWM_MAX 0xFFFF
#define PWM_TOP 0xBD70
#define PWM OCR0A

void setupPWM();

#endif
