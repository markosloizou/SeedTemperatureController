#include "StateController.h"

void changeState(sensor * sensor, reading_state * state)
{
    switch(*state)
    {
        case READ:
            switch(*sensor)
            {
                case INTERNAL:
                    *sensor = PLATE; 
                    break;
                case PLATE:
                   *sensor = SOIL; 
                    break;
                case SOIL:
                    *sensor = AMBIENT;
                    break;
                case AMBIENT:
                    *sensor = INTERNAL;
                    *state = SET;
                    break;
                default:
                    *sensor = SOIL;
                    *state = READ;
                    break;
            }
            break;
        case SET:
            switch(*sensor)
            {
                case INTERNAL:
                    *sensor = PLATE;
                    break;
                case PLATE:
                    *sensor = SOIL;
                    break;
                case SOIL:
                    *sensor = AMBIENT;
                    *state = OFF;
                    break;
                default:
                    *sensor = SOIL;
                    *state = READ;
                    break;
            }
            break;
        case OFF:
            *state = READ;
            *sensor = INTERNAL;
            break;
        default:
            //set state to read internal?
            *sensor = SOIL;
            *state = READ;
            break;
        
    }
}