#ifndef __TIMER_H_
#define __TIMER_H_

#include "stm32f4xx.h"


#define SR_UIF		(1U<<0)
#define	SR_CCIIF	(1U<<1)

void tim2_PA5_outputCapture(void);
void tim2_1hz_init(void);
void tim3_pa6_inputCapture(void);

#endif
