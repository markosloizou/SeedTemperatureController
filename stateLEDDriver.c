#include "stateLEDDriver.h"


void setStateLEDs(reading_state rState, sensor currentSensor)
{
    LED_INTERNAL_PORT &= !(1<<LED_INTERNAL_PIN);
    LED_PLATE_PORT    &= !(1<<LED_PLATE_PIN);
    LED_SOIL_PORT     &= !(1<<LED_SOIL_PIN);
    LED_AMBIENT_PORT  &= !(1<<LED_AMBIENT_PIN);
    LED_READ_PORT     &= !(1<<LED_READ_PIN);
    LED_SET_PORT      &= !(1<<LED_SET_PIN);


    switch(rState)
    {
        case READ:
            LED_READ_PORT |= (1<<LED_READ_PIN);
            break;
        case SET:
            LED_SET_PORT |= (1<<LED_SET_PIN);
            break;
        case OFF:
            return;
        default:
            break;
    }
    
    switch(currentSensor)
    {
        case AMBIENT:
            LED_AMBIENT_PORT |= (1<<LED_AMBIENT_PIN);
            break;
        case INTERNAL:
            LED_INTERNAL_PORT |= (1<<LED_INTERNAL_PIN);
            break;
        case PLATE:
            LED_PLATE_PORT |= (1<<LED_PLATE_PIN);
            break;
        case SOIL:
            LED_SOIL_PORT |= (1<< LED_SOIL_PIN);
            break;
    }
}



