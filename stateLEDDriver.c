#include "stateLEDDriver.h"
#include "mcc_generated_files/pin_manager.h"


void setStateLEDs(reading_state rState, sensor currentSensor)
{
    LED_INTERNAL_PIN_SetLow();
    LED_PLATE_PIN_SetLow();
    LED_SOIL_PIN_SetLow();
    LED_AMBIENT_PIN_SetLow();
    LED_READ_PIN_SetLow();
    LED_SET_PIN_SetLow();




    switch(rState)
    {
        case READ:
            LED_READ_PIN_SetHigh();
            break;
        case SET:
            LED_SET_PIN_SetHigh();
            break;
        case OFF:
            return;
        default:
            break;
    }
    
    switch(currentSensor)
    {
        case AMBIENT:
            LED_AMBIENT_PIN_SetHigh();
            break;
        case INTERNAL:
            LED_INTERNAL_PIN_SetHigh();
            break;
        case PLATE:
            LED_PLATE_PIN_SetHigh();
            break;
        case SOIL:
            LED_SOIL_PIN_SetHigh();
            break;
    }
}



