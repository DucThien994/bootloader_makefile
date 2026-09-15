#ifndef _USART_H_
#define _USART_H_

#include "gpio.h"

#define rx_buffer_size      (48 * 1024) // kich thuoc buffer 48kB 
#define rx_buf[rx_buffer_size];

void Usart_Init(void);
void USART1_IRQHandler(void);

#endif
