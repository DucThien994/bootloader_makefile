#include "adc.h"

void temperature_sensor_init(void){
    RCC_APB2ENR |= 1 << 8; // enable clock adc1 
    ADC_JSQR = 18 << 15;
    ADC_SMPR1 |= 0b111 << 24; // 480 cycles 
    ADC_CCR |= 1 << 23; // enable power supply for sensor
    ADC_CR2 |= 1 << 0; // enable ADC1

}

float read_temperature(void){
    ADC_CR2 |= 1 << 22; // enable bit 22 JSWSTART to start
    while(((ADC_SR >> 2) & 1) == 0); // conversion complete 

    uint16_t adc_val = (uint16_t)(ADC_JDR1 & 0xFFF);
    float v_sense = ((float)adc_val *3.3f)/4095.0f;
    float temperature = ((v_sense - 0.76f) / 0.0025f) + 25.0f; 
    return temperature; 
}