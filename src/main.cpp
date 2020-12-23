#include "./circuit/DCMD2020.hpp"

using namespace DCMD2020;

int main(void)
{
    DCMD2020::setup();
    //tim3.enableCount();
    //DCMD2020::ledPin[0].write(1);
    //DCMD2020::ledPin[1].write(1);
    //DCMD2020::ledPin[2].write(1);
    //DCMD2020::ledPin[3].write(1);
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

    }
}

void interrupt(void)
{
    //static uint16_t cnt = 0;
    //if(++cnt >= 100)
    //{
    //    cnt = 0;
    //    ledPin[0].toggle();
    //}

}

