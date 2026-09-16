#include "timer.h"

void timer1_init(void){
    RCC_APB2ENR |= 1 << 0; // enable clock timer 1 
    TIM1_PSC = 16000 - 1; 
    TIM1_EGR |= 1 << 0; 

}

void delay_timer(uint32_t ms){
    TIM1_ARR = ms - 1; 
    TIM1_CNT = 0; 
    TIM1_SR &= ~(1 << 0); // clear interrupt flag
    TIM1_CR1 |=  1 << 0;  // enable counter 

    while (((TIM1_SR >> 0) & 1) == 0); // update interrupt flag 

    TIM1_CR1 &= ~(1 << 0); // disable tim1 
    TIM1_SR &= ~(1 << 0); //  clear interrupt flag again 
}