/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45Q10
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "global_defines.h"
#include "memory_manager.h"
#include "segmentDisplayDriver.h"
#include "temperature_sensor_driver.h"
#include "stateLEDDriver.h"
#include "HeatingElementController.h"
#include "rotaryEncoderDriver.h"
#include "StateController.h"

/*
                         Main application
 */

static int soil_temp_goal;

static int max_plate_temp;
static int max_internal_temp;

int ambient_temp, plate_temp, soil_temp, internal_temp;


void PrintTemp(sensor currentSensor, reading_state state);

sensor currentSensor = AMBIENT; 
reading_state currentSensorState = READ;

void main(void)
{
    
    // Initialize the device
    SYSTEM_Initialize();
    ADCC_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    readSoilTempGoal(&soil_temp_goal);
    readPlateMax(&max_plate_temp);
    readInternalMax(&max_internal_temp);
    
    HC_setSoilTempGoil(soil_temp_goal);    
    HC_setMaxPlateTemp(max_plate_temp);
    HC_setMaxInternalTemp(max_internal_temp);
    
    ambient_temp = readTemperatureSensor(AMBIENT_TMP_CHANNEL);
    plate_temp = readTemperatureSensor(PLATE_TMP_CHANNEL);
    internal_temp = readTemperatureSensor(INTERNAL_TMP_CHANNEL);
    soil_temp = readTemperatureSensor(SOIL_TMP_CHANNEL);
    
    setDisplayTemperature(ambient_temp);
    openDisplay();
    
    TMR1_StartTimer();
    TMR3_StartTimer();
    TMR5_StartTimer();

    setStateLEDs(currentSensorState, currentSensor);
    HC_initialize();
    

    while (1)
    {
        // Add your application code
        HC_regulateTemperature(soil_temp, plate_temp, internal_temp);
        
        if(isSwitchPressed())
        {
            //change state
            changeState(&currentSensor, &currentSensorState);
        }
        
        int change = getEncoderChange();
        if(change && currentSensorState == SET)
        {
            switch(currentSensor)
            {
                case INTERNAL:
                    max_internal_temp += change;
                    HC_setMaxInternalTemp(max_internal_temp);
                    saveInternalMax(&max_internal_temp);
                    PrintTemp(currentSensor, currentSensorState);
                    break;
                case PLATE:
                    max_plate_temp += change; 
                    HC_setMaxPlateTemp(max_plate_temp);
                    savePlateMax(&max_plate_temp);
                    PrintTemp(currentSensor, currentSensorState);
                    break;
                case SOIL:
                    soil_temp_goal += change;
                    HC_setSoilTempGoil(soil_temp_goal);
                    saveSoilTempGoal(&soil_temp_goal);
                    PrintTemp(currentSensor, currentSensorState);
                    break;
                default:
                    break;
            }
        }
        
        
    }
}


void PrintTemp(sensor currentSensor, reading_state state)
{
    if(state == OFF)
    {
        closeDisplay();
    }
    else
    {
        openDisplay();
    }
    
    if(state == READ)
    {
        if(currentSensor == AMBIENT)
        {
            setDisplayTemperature(ambient_temp);
        }
        else if(currentSensor == SOIL)
        {
            setDisplayTemperature(soil_temp);
        }
        else if(currentSensor == PLATE)
        {
            setDisplayTemperature(plate_temp);
        }
        else if(currentSensor == INTERNAL)
        {
            setDisplayTemperature(internal_temp);
        }
    }
    else if(state == SET)
    {
        if(currentSensor == SOIL)
        {
            setDisplayTemperature(soil_temp_goal);
        }
        else if(currentSensor == PLATE)
        {
            setDisplayTemperature(max_plate_temp);
        }
        else if(currentSensor == INTERNAL)
        {
            setDisplayTemperature(max_internal_temp );
        }
    }
    
}
/**
 End of File
*/