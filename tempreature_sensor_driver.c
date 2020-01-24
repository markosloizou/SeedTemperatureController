/*
 * File:   tempreature_sensor_driver.c
 * Author: marko
 *
 * Created on January 23, 2020, 5:01 PM
 */

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adcc.h"
#include "global_defines.h"
#include "temperature_sensor_driver.h"

static unsigned int ADCRead(unsigned int channel);

int readTemperatureSensor(unsigned int channel)
{

    unsigned int ADCvalue = ADCRead(channel);
    
    float temp =0.0; 
    float Vout = (float) ADCvalue * MCU_VOLTAGE * 1000 / 1024.0 ; //10 bit in mv
    temp = (Vout - VZEROC)/TC;
    
    return (int)temp*10; //measure in milli Celsius
}

static unsigned int ADCRead(unsigned int channel)
{
    ADCC_StartConversion(channel);
    while(!ADCC_IsConversionDone())
    {
        
    }
    return ADCC_GetConversionResult();
}
