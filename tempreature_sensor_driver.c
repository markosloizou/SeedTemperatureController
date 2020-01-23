/*
 * File:   tempreature_sensor_driver.c
 * Author: marko
 *
 * Created on January 23, 2020, 5:01 PM
 */

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "global_defines.h"
#include "temperature_sensor_driver.h"

static unsigned int ADCRead();

float readTemperatureSensor(unsigned int channel)
{
    ADC_SelectChannel(channel);
    unsigned int ADCvalue = ADCRead();
    
    float temp =0.0; 
    float Vout = (float) ADCvalue * MCU_VOLTAGE * 1000 / 1024.0 ; //10 bit in mv
    temp = (Vout - VZEROC)/TC;
    
    return temp;
}

static unsigned int ADCRead()
{
    ADC_StartConversion();
    while(!ADC_IsConversionDone())
    {
        
    }
    return ADC_GetConversionResult();
}
