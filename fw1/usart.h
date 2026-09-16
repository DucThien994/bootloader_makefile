#ifndef _USART_H_
#define _USART_H

#include "gpio.h"

void USART1_IRQHandler(void);
void usart_Config(void);
void usart_send(char data);
void my_print(const char *str, ...);
char usart_read(void);

extern volatile char rx_buffer[64]; 
extern volatile uint8_t rx_idx; 
extern volatile uint8_t rx_flag; // nhan du data -> bat co ngat 

#endif
