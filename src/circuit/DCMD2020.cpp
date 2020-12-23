#include "DCMD2020.hpp"
#include <stdarg.h>

namespace DCMD2020
{
GPIO ledPin[ONBOARD_LED_NUM];
GPIO dipSw[4];
GPIO swdio, swclk;
GPIO limitSwPin[ONBOARD_LIMITSW_NUM];
TIM tim1, tim3; //Encoder
TIM tim4;       //Motor
TIM tim2;       //Timer
USART usart1;

uint16_t m_delayCnt = 0;

void setup(void)
{
    RCC_Setup();
    GPIO_Setup();
    TIM_Setup();
    USART_Setup();

}

void RCC_Setup(void)
{
    RCC_Setup_72MHz();
}

void GPIO_Setup(void)
{
    ledPin[0].setup(PA7, GPIO::PUSHPULL);
    ledPin[1].setup(PA6, GPIO::PUSHPULL);
    ledPin[2].setup(PA3, GPIO::PUSHPULL);
    ledPin[3].setup(PA2, GPIO::PUSHPULL);
    dipSw[0].setup(PB2, GPIO::FLOATING);
    dipSw[1].setup(PB0, GPIO::FLOATING);
    dipSw[2].setup(PB10, GPIO::FLOATING);
    dipSw[3].setup(PB1, GPIO::FLOATING);
    limitSwPin[0].setup(PA15, GPIO::FLOATING);
    limitSwPin[1].setup(PB3, GPIO::FLOATING);
    limitSwPin[2].setup(PC13, GPIO::FLOATING);
    limitSwPin[3].setup(PC14, GPIO::FLOATING);

    //SWDピン設定
    swdio.setup(PA13, GPIO::ALT_PUSHPULL);
    swclk.setup(PA14, GPIO::ALT_PUSHPULL);
    setAlternate_JTAG_SWD(JTAG_SWD_MODE::SWDP);
}

void TIM_Setup(void)
{
    //旧
    tim2.setupTimer(TIM2, 12, 1000000);
    tim3.setupEncoder(TIM3, PB4, PB5, 65535);
    tim1.setupEncoder(TIM1, PA0, PA1, 65535);
    //tim3.enableCount();

    //新
    //tim2.setup(TIM2, 1000000);
    //tim1.setup(TIM1, PA0, PA1);
    //tim3.setup(TIM3, PB4, PB5, 65536);
    //tim4.setup(TIM4, PB6, PB7, PB8, PB9);
}

void USART_Setup(void)
{
    usart1.setup(USART1, PA9, PA10, 115200);
}

void ADC_Setup(void)
{
    //pa5, pa4

}

void interrupt(void)
{
    if(m_delayCnt) m_delayCnt--;
    //usart1.printf("%d\n", m_delayCnt);
}

void delay_us(uint16_t time)
{

}


void delay_ms(uint16_t time)
{
    m_delayCnt = time;
    while(m_delayCnt) usart1.printf("");    //なんかこれつけないとwhile抜けない
}

}//namespace
