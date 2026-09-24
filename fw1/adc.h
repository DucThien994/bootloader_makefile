#ifndef _ADC_H_
#define _ADC_H_

#include "gpio.h"
void delay_ms(uint32_t ms);
void temperature_sensor_init(void);
float read_temperature(void);

#endif