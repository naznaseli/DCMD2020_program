#include "interrupt.hpp"

extern void interrupt(void);

void TIM1_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

void TIM1_IRQHandler(void)
{
    TIM1->SR = 0;
}

void TIM2_IRQHandler(void)
{
    TIM2->SR = 0;
    interrupt();

}

void TIM3_IRQHandler(void)
{
    TIM3->SR = 0;
    //interrupt();
}

void TIM4_IRQHandler(void)
{
    TIM4->SR = 0;
}
