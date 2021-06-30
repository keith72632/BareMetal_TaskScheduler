#include <stdint.h>

void uart_init()
{
    uint32_t *pRccAhb1   = (uint32_t *)0x40023830;
    uint32_t *pRccApb1   = (uint32_t *)0x40023840;
    uint32_t *pGpioAMode = (uint32_t *)0x40020000;
    uint32_t *pGpioAltFunc = (uint32_t *)0x40020020;

//    *pRccAhb1 &= ~(0xffffffff);
    *pRccAhb1 |= (1 << 0);

    *pRccApb1 &= ~(0xffffffff);
    *pRccApb1 |= (1 << 17);

    *pGpioAMode |= (2 << 4) | (2 << 6);

    *pGpioAltFunc |= (7 << 8) | (7 << 12);

    uint32_t *pUsart_Brr = (uint32_t *)0x40004408;
    uint32_t *pUsart_Cr1 = (uint32_t *)0x4000440C;

    *pUsart_Cr1 = 0x00;
    *pUsart_Cr1 |= (1 << 13);//UE bit
    *pUsart_Cr1 &= ~(1 << 12);//Make sure M bit is zero for 8 data bits;
    *pUsart_Brr |= (3 << 0) | (104 << 4);//0x0683 baud rate of 9600
    *pUsart_Cr1 |= (1 << 3) | (1 << 2); //enable TE and RE


}

void uputc(char c)
{
    uint32_t *pUsart_Sr = (uint32_t *)0x40004400;
    uint32_t *pUsart_Dr = (uint32_t *)0x40004404;


    if(!(*pUsart_Sr & 0x0080)){};
    *pUsart_Dr = (c & 0xff);

}

void uputs(char *s)
{
    uint32_t *pUsart_Sr = (uint32_t *)0x40004400;
    uint32_t *pUsart_Dr = (uint32_t *)0x40004404;
    
    for(int i = 0; s[i] != '\n'; i++)
    {
        uputc(s[i]);
    }

}
