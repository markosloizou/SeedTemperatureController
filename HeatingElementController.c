#include "HeatingElementController.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"

typedef enum{LOW_HEATING=1, MEDIUM_HEATING=2, HIGH_HEATING=3, OFF=0} heatingLevel; 


static int soilTgoal, internalTcutoff, plateTcutoff; 

static heatingLevel hLevel; 
static heatingLevel previousHLevel;
static int startingT; 

static int highHeatingDeviation = 80;
static int mediumHeatingDeviation = 80;
static int lowHeatingDeviation = 80;


void HC_setMaxInternalTemp(int t)
{
    internalTcutoff = t; 
}


void HC_setMaxPlateTemp(int t)
{
    plateTcutoff = t;
}


void HC_setSoilTempGoil(int t)
{
    soilTgoal = t;
}

void HC_initialize()
{
    RELAY_PIN_SetHigh();
    ISOURCE1_PIN_SetLow();
    ISOURCE2_PIN_SetLow();
    hLevel = HIGH_HEATING;
    previousHLevel = HIGH_HEATING;
    TMR0_StartTimer();
}


void HC_regulateTemperature(int soilT, int plateT, int internalT)
{
    //degrees measured in Celsius x 10
   
    
    if( soilT > (soilTgoal + 10))
    {
        TMR0_StopTimer();
        TMR0_Reload();
        hLevel = OFF;
    }
    
    
    if(soilTgoal < soilT - highHeatingDeviation)
    {
        hLevel = HIGH_HEATING;
    }
    else if(soilTgoal < soilT-mediumHeatingDeviation)
    {
        hLevel = MEDIUM_HEATING;
    }
    else if(soilTgoal < soilT - lowHeatingDeviation)
    {
        hLevel = LOW_HEATING;
    }
    
    
    if(hLevel != previousHLevel)
    {
        // if hlevel == off all good
        
        if(hLevel == OFF)
        {
            previousHLevel = OFF;
            TMR0_StopTimer();
            TMR0_Reload();
        }
        
        
        //if less heating is required
        if(hLevel < previousHLevel)
        {
            // increase thresholds (more negative) since less heating is required
            if(previousHLevel == HIGH_HEATING) highHeatingDeviation++;
            if(previousHLevel == MEDIUM_HEATING ) mediumHeatingDeviation++;
            if(previousHLevel == LOW_HEATING) lowHeatingDeviation++;
            previousHLevel = hLevel;
            TMR0_StopTimer();
            TMR0_Reload();
            TMR0_StartTimer();
        }
        
        //if more heating is required
        if(hLevel > previousHLevel)
        {
            
            unsigned long t = TMR0_ReadTimer();
            if(TMR0_HasOverflowOccured())
            {
                TMR0_StopTimer();
                TMR0_Reload();
                TMR0_StartTimer();
                t += 0xFFFF; 
            }
            //timer zero parameters, each tick ~2mS 
            // x25/1000 to get seconds
            // 
            if(t * 25 / 1000 > 120)
            {
                if(previousHLevel == HIGH_HEATING) highHeatingDeviation++;
                if(previousHLevel == MEDIUM_HEATING ) mediumHeatingDeviation++;
                if(previousHLevel == LOW_HEATING) lowHeatingDeviation++;
                
                TMR0_StopTimer();
                TMR0_Reload();
                TMR0_StartTimer();
                
                previousHLevel = hLevel; 
            }
        }
    }
    
      
    if(plateT > plateTcutoff || internalT > internalTcutoff)
    {
        RELAY_PIN_SetLow();
        ISOURCE1_PIN_SetLow();
        ISOURCE2_PIN_SetLow();
        TMR0_StopTimer();
    } 
    else
    {
        switch(previousHLevel)
        {
            case HIGH_HEATING:
                RELAY_PIN_SetHigh();
                ISOURCE1_PIN_SetLow();
                ISOURCE2_PIN_SetLow();
                break;
            case MEDIUM_HEATING:
                RELAY_PIN_SetLow();
                ISOURCE1_PIN_SetHigh();
                ISOURCE2_PIN_SetLow();
                break;
            case LOW_HEATING:
                RELAY_PIN_SetLow();
                ISOURCE1_PIN_SetLow();
                ISOURCE2_PIN_SetHigh();
                break;
            case OFF:
                RELAY_PIN_SetLow();
                ISOURCE1_PIN_SetLow();
                ISOURCE2_PIN_SetLow();
                break;
            default:
                RELAY_PIN_SetLow();
                ISOURCE1_PIN_SetLow();
                ISOURCE2_PIN_SetLow();
                break;
        }
    }
}

