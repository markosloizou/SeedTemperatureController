# 1 "rotaryEncoderDriver.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:\\programs\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "rotaryEncoderDriver.c" 2
# 1 "./rotaryEncoderDriver.h" 1
# 11 "./rotaryEncoderDriver.h"
int previousSwitchState = 0;
int previousA1State = 0;
int previousC1State = 1;


int getEncoderChange();
int isSwitchPressed();

void setSwitchState(int state);
void setEncoderState(int state);
# 1 "rotaryEncoderDriver.c" 2


static volatile int SwitchState = 0;
static volatile int EncoderState = 0;

void setSwitchState(int s)
{
    SwitchState = s;
}
void setEncoderState(int state)
{
    EncoderState = state;
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
