#include "usart.h"

void Usart_Config(void){
    GPIOB_MODER &= ~(0xF << 12);
    GPIOB_MODER |= 0b10 << 12;
    GPIOB_MODER |= 0b10 << 14;

    // alternate function usart for pb6 pb7 
    GPIOB_AFRL &= ~(0xFF << 24);
    GPIOB_AFRL |= 0b111 << 24; 
    GPIOB_AFRL |= 0b111 << 28; 
    GPIOB_OSPEED &= ~(0xF << 12);
    GPIOB_OSPEED |= 0xF << 12;


}

void Usart_Init(void){
    // enable clock 
    RCC_APB2ENR |= 1 << 4; 

    // config baudrate 115200 bit/s
    // 8N1, 8 bit data, no parity, 1 stop bit 
    
    // div_man: 8 | div_fraction: 11
    USART1_BRR = 0x8B;
    USART1_CR1 |= 1 << 12; // word length 8 data bits, 1 stop bit
    USART1_CR1 &= ~(1 << 10); // parity control disable 
    USART1_CR1 |= 1 << 2; // receiver enable 
    USART1_CR1 |= 1 << 3; // transmitter enable
    USART1_CR1 |= 1 << 13; // enable uart 

    NVIC_ISER1 |= 1 << (37 - 32); // enable NVIC vector table 

}

void USART1_IRQHandler(void){

}
