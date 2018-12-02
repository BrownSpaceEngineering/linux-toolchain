#include <samd21.h>

static void delay(int n)
{
    int i;

    for (;n >0; n--)
    {
        for (i=0;i<100;i++)
            __asm("nop");
    }
}

int main(void)
{
    REG_PORT_DIR1 |= (1<<30);
    while (1)
    {
        REG_PORT_OUT1 &= ~(1<<30);
        delay(100);
        REG_PORT_OUT1 |= (1<<30);
        delay(100);
	REG_PORT_OUT1 &= ~(1<<30);
        delay(100);
        REG_PORT_OUT1 |= (1<<30);
        delay(100);
	REG_PORT_OUT1 &= ~(1<<30);
        delay(100);
        REG_PORT_OUT1 |= (1<<30);
        delay(1000);

    }
}
