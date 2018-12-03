#include <samd21.h>
#include <delay.h>

/*
static void delay(int n)
{
    int i;

    for (;n >0; n--)
    {
        for (i=0;i<100;i++)
            __asm("nop");
    }
}
*/

int main(void)
{
    delay_init();
    REG_PORT_DIR1 |= (1<<30);
    while (1)
    {
        REG_PORT_OUT1 &= ~(1<<30);
        delay_ms(100);
        REG_PORT_OUT1 |= (1<<30);
        delay_ms(100);
	REG_PORT_OUT1 &= ~(1<<30);
        delay_ms(100);
        REG_PORT_OUT1 |= (1<<30);
        delay_ms(100);
	REG_PORT_OUT1 &= ~(1<<30);
        delay_ms(100);
        REG_PORT_OUT1 |= (1<<30);
        delay_ms(1000);

    }
}
