#include "timer.h"

#define TIM2EN			(1U<<0)
#define TIM3EN			(1U<<1)
#define CRI_CEN			(1U<<0)
#define OC_TOGGLE		(1U<<4) | (1U<<5)
#define OC_PWM			(1U<<5) | (1U<<6)
#define CCER_CCIE		(1U<<0)

#define GPIOAEN			(1U<<0)
#define AFR5_TIM		(1U<<20)

#define AFR6_TIM		(1U<<25)
#define CCER_CC1S		(1U<<0)



void tim2_1hz_init(void){

	/* Enable GPIOA clock */
	RCC->APB1ENR |= TIM2EN;
	/* Set Prescaler */
	TIM2->PSC = 1600 - 1;
	/* Set Auto reload Register */
	TIM2->ARR = 10000 - 1;
	/* Clear Counter */
	TIM2->CNT	= 0;
	/* Turn ON Timer */
	TIM1->CR1 = CRI_CEN;
		
}

void tim2_PA5_outputCapture(void){

	/* Enable GPIOA clock */
	RCC->AHB1ENR  |= GPIOAEN;
	/* PA5 in Alternate function */
	GPIOA->MODER &= ~(1U<<10);
	GPIOA->MODER |= (1U<<11);
	/* PA5 in Alternate Function TIM2_CH1 */
	GPIOA->AFR[0] |= AFR5_TIM;
	/* Enable TIMER2 Counter */
	RCC->APB1ENR |= TIM2EN;
		/* Set Prescaler */
	TIM2->PSC = 1600 - 1;
	/* Set Auto reload Register */
	TIM2->ARR = 10000 - 1;
	
	//TIM2->CCR1 = 4999;
	
	TIM2->CCMR1 = OC_TOGGLE;
	
	TIM2->CCER |= CCER_CCIE;
	/* Clear Counter */
	TIM2->CNT	= 0;
	/* Turn ON Timer */
	TIM2->CR1 = CRI_CEN;
	
}

void tim3_pa6_inputCapture(void){

	/* Enable GPIOA clock */
	RCC->AHB1ENR  |= GPIOAEN;
	/* PA5 in Alternate function */
	GPIOA->MODER &= ~(1U<<12);
	GPIOA->MODER |= (1U<<13);
	/* PA5 in Alternate Function TIM2_CH1 */
	GPIOA->AFR[0] |= AFR6_TIM;
	/* Enable TIMER3 Counter */
	RCC->APB1ENR |= TIM3EN;
	/* Set Prescaler */
	TIM3->PSC = 16000 - 1;
	/* Set CH1 to input capture */
	TIM3->CCMR1 = CCER_CC1S;
	
	TIM3->CCER |= CCER_CCIE;
	
	/* Turn ON Timer */
	TIM3->CR1 = CRI_CEN;
}

