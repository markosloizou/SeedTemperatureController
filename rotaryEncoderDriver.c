#include "rotaryEncoderDriver.h"

static volatile int SwitchState = 0; 
static volatile int EncoderState = 0; 

void setSwitchState(int s)
{
    SwitchState = s;
}
void setEncoderState(int state)
{
    EncoderState += state; 
}

int getEncoderChange()
{
    int temp = EncoderState;
    EncoderState = 0;
    return temp;
}

int isSwitchPressed()
{
    if(SwitchState > 1)
    {
        SwitchState = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}
