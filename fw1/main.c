#include <stdio.h>
#include "gpio.h"
#include "timer.h"
#include "adc.h"
#include "usart.h"


void SystemInit(void){
    *(volatile uint32_t *)(0xE000ED88) |= (0xF << 20);
}

int main(){

    usart_Config();
    temperature_sensor_init();
    timer1_init();

    my_print("This is firmware for getting temperature data\n "); 

    while(1){

        float temp = read_temperature();

        int temp_int = (int)(temp);
        int temp_dec = (int)((temp - (float)temp_int) * 100.f);
        if(temp_dec <0) temp_dec = -temp_dec;

        // my_print("Temperature of STM32F411 : %d C\r\n", temp);
        my_print("Temperature of STM32: %d.%02d C\r\n", temp_int, temp_dec);

        delay_timer(1000); // 1000ms 
    }
    return 0; 
}