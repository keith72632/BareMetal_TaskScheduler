/*
 * led.h
 *
 *  Created on: 28-Dec-2019
 *      Author: nieki
 */
#include <stdint.h>
#ifndef LED_H_
#define LED_H_

#define LED_GREEN  12
#define LED_ORANGE 13
#define LED_RED    14
#define LED_BLUE   15

#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)
#define INPUT                   0x00
#define OUTPUT                  0x01
/*
void led_init_all(void);
void led_on(uint8_t led_no);
void led_off(uint8_t led_no);
void delay(uint32_t count);
*/

class Led
{
    private:
        uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
        uint32_t *pGpioModeA    = (uint32_t *)0x40020000;
        uint32_t *pGpioModeB    = (uint32_t *)0x40020400;
        uint32_t *pGpioModeC    = (uint32_t *)0x40020800;
        uint32_t *pGpioModeD = (uint32_t*)0x40020C00;
        uint32_t *pGpioModeE    = (uint32_t *)0x40021000;
        uint32_t *pGpioModeF    = (uint32_t *)0x40021400;
        uint32_t *pGpioModeG    = (uint32_t *)0x40021800;
        uint32_t *pGpioModeH    = (uint32_t *)0x40021C00;
        uint32_t *pGpioModeI    = (uint32_t *)0x40022000;
        uint32_t *pGpioModeJ    = (uint32_t *)0x40022400;
        uint32_t *pGpioModeK    = (uint32_t *)0x40022800;
        uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
        uint32_t pinNumber;
    public:
        Led(uint32_t clockNum, uint32_t pinNum, uint32_t mode);
        void turnOnLed();
        void turnOffLed();
        ~Led();
};

#endif /* LED_H_ */
