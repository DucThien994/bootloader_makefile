#include "adc.h"

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 3200; j++)
        {
            __asm volatile ("nop");
        }
    }
}

void temperature_sensor_init(void){
    RCC_APB2ENR |= 1 << 8; // enable clock adc1 
    ADC_CCR |= 1 << 23; // enable power supply for sensor
    ADC_SQR3 = 16;
    ADC_SMPR1 |= 0b111 << 18; // 480 cycles 
    ADC_CR2 |= 1 << 0; // enable ADC1
    delay_ms(15);
}

float read_temperature(void){

    ADC_CR2 |= 1 << 30;

    while(((ADC_SR >> 1) & 1) == 0);

    // ADC_CR2 |= 1 << 22; // enable bit 22 JSWSTART to start 
    while(((ADC_SR >> 1) & 1) == 0); // conversion complete 
    
    // ADC_SR &= ~(1 << 2); // clear JEOC flag  

    uint16_t adc_raw = (uint16_t)(ADC_DR & 0x0FFF);
    
    float v_sense = (float)(adc_raw *3.3)/4095;
    float temperature = (float)(((v_sense - 0.76) / 0.0025) + 25.0); 
    
    return temperature; 
}
