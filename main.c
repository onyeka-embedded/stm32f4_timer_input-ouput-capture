#include "stm32f4xx.h"

#include "timer.h"

static volatile unsigned int timestamp;

int main(void){
	tim2_PA5_outputCapture();
	tim3_pa6_inputCapture(); 
while(1){
	/* Wait until edge is captured */		
	while(!(TIM1->SR & SR_CCIIF)){
		/* Read the captured value */
		timestamp = TIM3->CCR1;
		}
	
	}
}
