#include "usart.h"

volatile char rx_buffer[64]; 
volatile uint8_t rx_idx = 0; 
volatile uint8_t rx_flag = 0;

void usart_Config(void) {

    RCC_AHB1ENR |= 1 << 1;                      // enable clock gpiob
    GPIOB_MODER &= ~(0xF << 12);                // reset reg
    GPIOB_MODER |= (0b10 << 12) | (0b10 << 14); // alternate func
    GPIOB_AFRL &= ~(0xFF << 24);                // reset reg alternate
    GPIOB_AFRL |= (0b0111 << 24) | (0b0111 << 28);  
    
    /*
    - PB6 TX
    - PB7 RX
    - baudrate 115200 bit/s
    - data size : 8bit -> CR1 bit 12 M
    - parity : none
    - enable transmitter and receiver
    - enable usart 1
    */
    
    RCC_APB2ENR |= 1 << 4; // enable clock usart1
    USART1_BRR = 0x8B;
    USART1_CR1 &= ~(1 << 12); // word length
    USART1_CR1 &= ~(1 << 10); // none parity
    USART1_CR1 |= 1 << 2;     // receiver enable
    USART1_CR1 |= 1 << 3;     // transmitter enable

    USART1_CR1 |= 1 << 5; // read data reg not empty 
    NVIC_ISER1 |= 1 << (37 - 32); // NVIC 

    USART1_CR1 |= 1 << 13;    // usart1 enable
}

// ham lay du lieu tu uart
void usart_send(char data) {
    while (((USART1_SR >> 7) & 1) == 0); // bit 7 : Transmit data register empty
  USART1_DR = (data & 0xFF);
}

void my_print(const char *str, ...) {
    va_list list;
    va_start(list, str);
    char print_buf[128] = {0};
    vsnprintf(print_buf, sizeof(print_buf), str, list);
    
    int len = strlen(print_buf);
    
    for (int i = 0; i < len; i++) {
      usart_send(print_buf[i]);
    }   
    
    va_end(list);
}

char usart_read(void){
    while(((USART1_SR >> 5) & 1) == 0); 
    return (char)(USART1_DR & 0xFF); 
}

void USART1_IRQHandler(void){
    
    if(((USART1_SR >> 5) & 1) == 1){
        char data = (char)(USART1_DR & 0xFF); 
        
        if (data == '\r' || data == '\n') {
            if (rx_idx > 0){
                rx_buffer[rx_idx] = '\0'; // ket thuc chuoi 
                rx_flag = 1; 
                rx_idx = 0; 
            }
        }

        else if (rx_idx < sizeof(rx_buffer) - 1){
            rx_buffer[rx_idx++] = data;
        }   
    
    }
}

