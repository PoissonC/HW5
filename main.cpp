/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut led(PWM_OUT);

int main()
{
    // specify period first
    // led.period(0.05f);      // 4 second period
    // led.write(0.50f);
    while(1){
        for(float i=0.8;i>=0.3;i-=0.05){
            led.period(0.05f);      // 4 second period
            led.write(i);      // 50% duty cycle, relative to period
            wait_us(50000); 
        }
        led.write(0);
        wait_us(50000); 
    }
    //led = 0.5f;          // shorthand for led.write()
    //led.pulsewidth(2);   // alternative to led.write, set duty cycle time in seconds
    while (1);
}
