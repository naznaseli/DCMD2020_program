#pragma once
#include <stddef.h>
#include "./peripheral/RCC.hpp"
#include "./peripheral/GPIO.hpp"
#include "./peripheral/TIM.hpp"
#include "./peripheral/USART.hpp"
#include "./peripheral/bxCAN.hpp"
#include "./peripheral/IWDG.hpp"

#define ONBOARD_LED_NUM     4
#define ONBOARD_LIMITSW_NUM 4

namespace DCMD2020
{
extern GPIO ledPin[ONBOARD_LED_NUM];
extern GPIO dipSw[4];
extern GPIO limitSwPin[ONBOARD_LIMITSW_NUM];
extern TIM tim1, tim3; //Encoder
extern TIM tim4;       //Motor
extern TIM tim2;       //Timer
extern USART usart1;

//! setup
void setup(void);

//! 周期関数
void cycle(void);
void interrupt(void);

size_t millis(void);
void delay_us(uint16_t time);
void delay_ms(uint16_t time);

//! setup中身
void RCC_Setup(void);
void GPIO_Setup(void);
void TIM_Setup(void);
void USART_Setup(void);
void ADC_Setup(void);
void bxCAN_Setup(void);
void IWDG_Setup(void);

}//namespace
