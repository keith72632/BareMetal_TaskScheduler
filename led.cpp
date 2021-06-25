#include <cstdint>
#include "led.h"

Led::Led(uint32_t clockNum, uint32_t pinNum, uint32_t mode)
{
    pinNumber = pinNum;
    *pRccAhb1enr |= ( 1 << clockNum);
    //configure LED_GREEN
    *pGpioModeD |= ( mode << (2 * pinNum));
}
        
void Led::turnOnLed()
{
    *pGpiodDataReg |= ( 1 << pinNumber);
}

void Led::turnOffLed()
{
    *pGpiodDataReg &= ~(1 << pinNumber);
}

Led::~Led()
{
};
