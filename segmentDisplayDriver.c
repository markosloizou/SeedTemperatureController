#include "segmentDisplayDriver.h"
#include "global_defines.h"
#include "mcc_generated_files/pin_manager.h"

static void printCharacter(int n); // n must be between 0 and 9
static void setDP();
static void clearDisplay();

static int temperature = 0; 
static int DisplayOn = 1;

void setDisplayTemperature(int temp)
{
    temperature = temp;
}

void closeDisplay()
{
    DisplayOn = 0;
}
void openDisplay()
{
    DisplayOn = 1;
}

void printTemperature()
{
    static short digit = 1;
    
    if(DisplayOn == 0)
    {
        clearDisplay();
        return;
    }
    
    if(digit == 1)
    {
        clearDisplay();
        //clear other digits
        DIGIT2_PIN_SetLow();
        DIGIT3_PIN_SetLow();
        //set digit
        DIGIT1_PIN_SetHigh();
        printCharacter(temperature/100);
        digit++;
    }
    else if(digit == 2)
    {
        clearDisplay();
       //clear other digits
        DIGIT1_PIN_SetLow();
        DIGIT3_PIN_SetLow();
        //set digit
        DIGIT2_PIN_SetHigh();
        
        int t = temperature / 10; 
        printCharacter(t%10);
        setDP();
        
        digit++;
    }
    else if(digit == 3)
    {
        clearDisplay();
        //clear digits
        //clear other digits
        DIGIT1_PIN_SetLow();
        DIGIT2_PIN_SetLow();
        //set digit
        DIGIT3_PIN_SetHigh();
        
        printCharacter(temperature%10);
        digit++;
    }
}

static void printCharacter(int n)
{
    switch(n)
    {
        case 0:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGE_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            break;
        case 1:
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            break;
        case 2:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGE_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            break;
        case 3:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            break;
        case 4:
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            break;
        case 5:
            SEGA_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            break;
        case 6:
            SEGA_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGE_PIN_SetHigh();
            break;
        case 7:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            break;
        case 8:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGE_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            break;
        case 9:
            SEGA_PIN_SetHigh();
            SEGB_PIN_SetHigh();
            SEGC_PIN_SetHigh();
            SEGD_PIN_SetHigh();
            SEGF_PIN_SetHigh();
            SEGG_PIN_SetHigh();
            break;
        default:
            break;
    }
}

static void setDP()
{
    SEGDP_PIN_SetHigh();
}

static void clearDisplay()
{
   SEGA_PIN_SetLow();
    SEGB_PIN_SetLow();
    SEGC_PIN_SetLow();
    SEGD_PIN_SetLow();
    SEGE_PIN_SetLow();
    SEGF_PIN_SetLow();
    SEGG_PIN_SetLow();

}

