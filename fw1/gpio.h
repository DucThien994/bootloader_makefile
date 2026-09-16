#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define GPIOA_BASE_ADDR         0x40020000
#define GPIOB_BASE_ADDR         0x40020400
#define GPIOD_BASE_ADDR         0x40020C00
#define RCC_BASE_ADDR           0x40023800
#define USART1_BASE_ADDR        0x40011000
#define ADC_BASE_ADDR           0x40012000 
#define TIM1_BASE_ADDR          0x40010000

#define NVIC_ISER1              (*(volatile uint32_t *)(0xE000E104))
#define NVIC_ISER0              (*(volatile uint32_t *)(0xE000E100))
#define RCC_AHB1ENR             (*(volatile uint32_t *)(RCC_BASE_ADDR + 0x30))
#define RCC_APB1ENR             (*(volatile uint32_t *)(RCC_BASE_ADDR + 0x40))
#define RCC_APB2ENR             (*(volatile uint32_t *)(RCC_BASE_ADDR + 0x44))

#define GPIOA_IDR               (*(volatile uint32_t *)(GPIOA_BASE_ADDR + 0x10))
#define GPIOB_MODER             (*(volatile uint32_t *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_AFRL              (*(volatile uint32_t *)(GPIOB_BASE_ADDR + 0x20))
#define GPIOB_OSPEED            (*(volatile uint32_t *)(GPIOB_BASE_ADDR + 0x08))
#define GPIOB_PUPDR             (*(volatile uint32_t *)(GPIOB_BASE_ADDR + 0x0C))

#define USART1_SR               (*(volatile uint32_t *)(USART1_BASE_ADDR + 0x00))
#define USART1_DR               (*(volatile uint32_t *)(USART1_BASE_ADDR + 0x04))
#define USART1_BRR              (*(volatile uint32_t *)(USART1_BASE_ADDR + 0x08))
#define USART1_CR1              (*(volatile uint32_t *)(USART1_BASE_ADDR + 0x0C))

#define TIM1_CR1                (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x00))
#define TIM1_DIER               (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x0C))
#define TIM1_SR                 (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x10))
#define TIM1_EGR                (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x14))
#define TIM1_CNT                (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x24))
#define TIM1_PSC                (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x28))
#define TIM1_ARR                (*(volatile uint32_t *)(TIM1_BASE_ADDR + 0x2C))

#define ADC_SR      (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x00))   
#define ADC_CR1     (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x04))   
#define ADC_JSQR    (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x38))   
#define ADC_CCR     (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x04 + 0x300))   
#define ADC_SMPR1   (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x0C))   
#define ADC_CR2     (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x08))
#define ADC_JDR1    (*(volatile uint32_t*)(ADC_BASE_ADDR + 0x54))


#endif