#include <stdio.h>
#include "gpio.h"
#include "timer.h"
#include "adc.h"
#include "usart.h"


void SystemInit(void){

}

int main(){

    usart_Config();
    temperature_sensor_init();
    timer1_init();

    my_print("This is firmware for getting temperature data"); 

    while(1){

        int temp = (int)read_temperature();
        my_print("Temperature of STM32F411 : %d C\r\n", temp);
        delay_timer(200); // 200ms 
    }
    return 0; 
}