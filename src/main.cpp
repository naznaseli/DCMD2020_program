#include "./circuit/DCMD2020.hpp"

using namespace DCMD2020;

int main(void)
{
    DCMD2020::setup();
    usart1.printf("F103 MD\n");
    while(1)
    {
        //usart1.printf("test\n");
        //if(!limitSwPin[0].read()) ledPin[0].write(1);
        //else ledPin[0].write(0);
        //if(!limitSwPin[1].read()) ledPin[1].write(1);
        //else ledPin[1].write(0);
        //if(!limitSwPin[2].read()) ledPin[2].write(1);
        //else ledPin[2].write(0);
        if(!limitSwPin[3].read()) ledPin[3].write(1);
        else ledPin[3].write(0);
        //if(!rotaryDipPin[0].read()) ledPin[0].write(1);
        //else ledPin[0].write(0);
        //if(!rotaryDipPin[1].read()) ledPin[1].write(1);
        //else ledPin[1].write(0);
        //if(!rotaryDipPin[2].read()) ledPin[2].write(1);
        //else ledPin[2].write(0);
        //if(!rotaryDipPin[3].read()) ledPin[3].write(1);
        //else ledPin[3].write(0);
        ledPin[1].write(1);
        delay_ms(1000);
        ledPin[1].write(0);
        delay_ms(1000);

    }
}

void interrupt(void)
{
    DCMD2020::interrupt();
    static uint16_t cnt = 0;
    if(++cnt >= 1000)
    {
        cnt = 0;
        ledPin[0].toggle();
        usart1.printf("%d\t%d\n", TIM3->CNT, TIM1->CNT);
    }

}

