#include "segmentDisplayDriver.h"
#include "global_defines.h"

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
        DIGIT2_PORT &= !(1<<DIGIT2_PIN);
        DIGIT3_PORT &= !(1<<DIGIT3_PIN);
        //set digit
        DIGIT1_PORT |= (1<<DIGIT1_PIN);
        printCharacter(temperature/100);
        digit++;
    }
    else if(digit == 2)
    {
        clearDisplay();
        //clear other digits
        DIGIT1_PORT &= !(1<<DIGIT1_PIN);
        DIGIT3_PORT &= !(1<<DIGIT3_PIN);
        
        //set digit
        DIGIT2_PORT |= (1<<DIGIT2_PIN);
        
        int t = temperature / 10; 
        printCharacter(t%10);
        setDP();
        
        digit++;
    }
    else if(digit == 3)
    {
        clearDisplay();
        //clear digits
        DIGIT1_PORT &= !(1<<DIGIT1_PIN);
        DIGIT2_PORT &= !(1<<DIGIT2_PIN);
        //set digit
        DIGIT3_PORT |= (1<<DIGIT3_PIN);
        
        printCharacter(temperature%10);
        digit++;
    }
}

static void printCharacter(int n)
{
    switch(n)
    {
        case 0:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            SEGE_PORT |= (1<<SEGE_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            break;
        case 1:
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            break;
        case 2:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            SEGE_PORT |= (1<<SEGE_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            break;
        case 3:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            break;
        case 4:
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            break;
        case 5:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            break;
        case 6:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            SEGE_PORT |= (1<<SEGE_PIN);
            break;
        case 7:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            break;
        case 8:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            SEGE_PORT |= (1<<SEGE_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            break;
        case 9:
            SEGA_PORT |= (1<<SEGA_PIN);
            SEGB_PORT |= (1<<SEGB_PIN);
            SEGC_PORT |= (1<<SEGC_PIN);
            SEGD_PORT |= (1<<SEGD_PIN);
            SEGF_PORT |= (1<<SEGF_PIN);
            SEGG_PORT |= (1<<SEGG_PIN);
            break;
        default:
            break;
    }
}

static void setDP()
{
    SEGDP_PORT |= (1<<SEGDP_PIN);
}

static void clearDisplay()
{
    SEGA_PORT &= !(1<<SEGA_PIN);
    SEGB_PORT &= !(1<<SEGB_PIN);
    SEGC_PORT &= !(1<<SEGC_PIN);
    SEGD_PORT &= !(1<<SEGD_PIN);
    SEGE_PORT &= !(1<<SEGE_PIN);
    SEGF_PORT &= !(1<<SEGF_PIN);
    SEGG_PORT &= !(1<<SEGG_PIN);
    SEGDP_PORT &= !(1<<SEGDP_PIN);

}

