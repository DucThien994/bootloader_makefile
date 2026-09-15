#ifndef _GPIO_H_
#define _GPIO_H_ 

#include <stdint.h>

#define GPIOA_BASE_ADDR     0x40020000
#define GPIOB_BASE_ADDR     0x40020400
#define GPIOD_BASE_ADDR     0x40020C00
#define RCC_BASE_ADDR       0x40023800
#define USART1_BASE_ADDR    0x40011000

#define NVIC_ISER1          (*(volatile uint32_t*)(0xE000E104))
#define RCC_AHB1ENR         (*(volatile uint32_t*)(RCC_BASE_ADDR + 0x30))
#define RCC_APB1ENR         (*(volatile uint32_t*)(RCC_BASE_ADDR + 0x40))
#define RCC_APB2ENR         (*(volatile uint32_t*)(RCC_BASE_ADDR + 0x44))

#define USART1_SR           (*(volatile uint32_t*)(USART1_BASE_ADDR + 0x00))
#define USART1_DR           (*(volatile uint32_t*)(USART1_BASE_ADDR + 0x04))
#define USART1_BRR          (*(volatile uint32_t*)(USART1_BASE_ADDR + 0x08))
#define USART1_CR1          (*(volatile uint32_t*)(USART1_BASE_ADDR + 0x0C))

#endif 