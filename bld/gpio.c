#include "gpio.h"

typedef enum {
    LED_GREEN = 12, 
    LED_ORANGE,
    LED_BLUE,
    LED_RED
}led_t;

void LedCtrl(led_t led, int on_off){
    if(on_off == 1){
        GPIOD_BSRR |= 1 << led; 
    }
    else {
        GPIOD_BSRR &= ~(1 << led);
    }
}

char ButtonState(){
    return ((GPIOA_IDR >> 0) & 1);
}

void led_on_off(){
    if(ButtonState())
        LedCtrl(LED_RED, 1);
    else 
        LedCtrl(LED_RED, 0);
}
