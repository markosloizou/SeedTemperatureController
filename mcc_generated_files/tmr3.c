/**
  TMR3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr3.c

  @Summary
    This is the generated driver implementation file for the TMR3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR3.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K20
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr3.h"
#include "../rotaryEncoderDriver.h"
#include "../global_defines.h"

/**
  Section: Global Variable Definitions
*/
volatile uint16_t timer3ReloadVal;
void (*TMR3_InterruptHandler)(void);

/**
  Section: TMR3 APIs
*/

void TMR3_Initialize(void)
{
    //Set the Timer to the options selected in the GUI
	
	// TMR3H 255; 
		TMR3H = 0xFF;
	
	// TMR3L 6; 
		TMR3L = 0x06;

    // Load the TMR value to reload variable
    timer3ReloadVal=TMR3;

    // Clearing IF flag before enabling the interrupt.
    PIR2bits.TMR3IF = 0;

    // Enabling TMR3 interrupt.
    PIE2bits.TMR3IE = 1;

    // Set Default Interrupt Handler
    TMR3_SetInterruptHandler(TMR3_DefaultInterruptHandler);

    // T3CKPS 1:1; TMR3CS FOSC/4; nT3SYNC synchronize; TMR3ON enabled; T3CCP1 Timer1 clk src; RD16 disabled; 
    T3CON = 0x01;
}

void TMR3_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 1;
}

void TMR3_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 0;
}

uint16_t TMR3_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
	
    T3CONbits.RD16 = 1;
	
    readValLow = TMR3L;
    readValHigh = TMR3H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR3_WriteTimer(uint16_t timerVal)
{
    if (T3CONbits.nT3SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T3CONbits.TMR3ON = 0;

        // Write to the Timer3 register
        TMR3H = (timerVal >> 8);
        TMR3L = (uint8_t) timerVal;

        // Start the Timer after writing to the register
        T3CONbits.TMR3ON =1;
    }
    else
    {
        // Write to the Timer3 register
        TMR3H = (timerVal >> 8);
        TMR3L = (uint8_t) timerVal;
    }
}

void TMR3_Reload(void)
{
    TMR3_WriteTimer(timer3ReloadVal);
}

void TMR3_ISR(void)
{

    // Clear the TMR3 interrupt flag
    PIR2bits.TMR3IF = 0;    
    TMR3_WriteTimer(timer3ReloadVal);

    // ticker function call;
    // ticker is 1 -> Callback function gets called every time this ISR executes
    TMR3_CallBack();
}

void TMR3_CallBack(void)
{
    // Add your custom callback code here

    if(TMR3_InterruptHandler)
    {
        TMR3_InterruptHandler();
    }
}

void TMR3_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR3_InterruptHandler = InterruptHandler;
}

void TMR3_DefaultInterruptHandler(void){
    // add your TMR3 interrupt custom code
    // or set custom function using TMR3_SetInterruptHandler()
    static int SwitchCount = 0;
    static int encoderA1Count = 0;
    static int encoderC1Count = 0; 
    
    static int switchPreviousStableState = 0;
    static int encoderA1PreviousStableState = 0;
    static int encoderC1PreviousStableState = 0;
    
    int currentA1, currentC1;
    
    if(switchPreviousStableState != ((ROTARY_SWITCH_PORT & (1 << ROTARY_SWITCH_PIN)) >> ROTARY_SWITCH_PIN)  ) 
    {
        SwitchCount++; 
        if(SwitchCount == STABLE_SWITCH_COUNT)
        {
            //changed state here
            if(switchPreviousStableState == 0) 
            {
                setSwitchState(1);
            }
            switchPreviousStableState = ((ROTARY_SWITCH_PORT & (1 << ROTARY_SWITCH_PIN)) >> ROTARY_SWITCH_PIN);
        }
    }
    
    currentA1 = (ROTARAY_A_PORT & (1 << ROTARY_A_PIN)) >> ROTARY_A_PIN; 
    currentC1 = (ROTARAY_C_PORT & (1 << ROTARY_C_PIN)) >> ROTARY_C_PIN; 
    
    
}

/**
 End of File
*/
