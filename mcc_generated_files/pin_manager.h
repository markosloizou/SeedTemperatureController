/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45Q10
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AMBIENT_TMP_CHANNEL aliases
#define AMBIENT_TMP_CHANNEL_TRIS                 TRISAbits.TRISA0
#define AMBIENT_TMP_CHANNEL_LAT                  LATAbits.LATA0
#define AMBIENT_TMP_CHANNEL_PORT                 PORTAbits.RA0
#define AMBIENT_TMP_CHANNEL_WPU                  WPUAbits.WPUA0
#define AMBIENT_TMP_CHANNEL_OD                   ODCONAbits.ODCA0
#define AMBIENT_TMP_CHANNEL_ANS                  ANSELAbits.ANSELA0
#define AMBIENT_TMP_CHANNEL_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define AMBIENT_TMP_CHANNEL_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define AMBIENT_TMP_CHANNEL_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define AMBIENT_TMP_CHANNEL_GetValue()           PORTAbits.RA0
#define AMBIENT_TMP_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define AMBIENT_TMP_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define AMBIENT_TMP_CHANNEL_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define AMBIENT_TMP_CHANNEL_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define AMBIENT_TMP_CHANNEL_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define AMBIENT_TMP_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define AMBIENT_TMP_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define AMBIENT_TMP_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set INTERNAL_TMP_CHANNEL aliases
#define INTERNAL_TMP_CHANNEL_TRIS                 TRISAbits.TRISA1
#define INTERNAL_TMP_CHANNEL_LAT                  LATAbits.LATA1
#define INTERNAL_TMP_CHANNEL_PORT                 PORTAbits.RA1
#define INTERNAL_TMP_CHANNEL_WPU                  WPUAbits.WPUA1
#define INTERNAL_TMP_CHANNEL_OD                   ODCONAbits.ODCA1
#define INTERNAL_TMP_CHANNEL_ANS                  ANSELAbits.ANSELA1
#define INTERNAL_TMP_CHANNEL_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define INTERNAL_TMP_CHANNEL_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define INTERNAL_TMP_CHANNEL_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define INTERNAL_TMP_CHANNEL_GetValue()           PORTAbits.RA1
#define INTERNAL_TMP_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define INTERNAL_TMP_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define INTERNAL_TMP_CHANNEL_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define INTERNAL_TMP_CHANNEL_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define INTERNAL_TMP_CHANNEL_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define INTERNAL_TMP_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define INTERNAL_TMP_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define INTERNAL_TMP_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set PLATE_TMP_CHANNEL aliases
#define PLATE_TMP_CHANNEL_TRIS                 TRISAbits.TRISA2
#define PLATE_TMP_CHANNEL_LAT                  LATAbits.LATA2
#define PLATE_TMP_CHANNEL_PORT                 PORTAbits.RA2
#define PLATE_TMP_CHANNEL_WPU                  WPUAbits.WPUA2
#define PLATE_TMP_CHANNEL_OD                   ODCONAbits.ODCA2
#define PLATE_TMP_CHANNEL_ANS                  ANSELAbits.ANSELA2
#define PLATE_TMP_CHANNEL_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PLATE_TMP_CHANNEL_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PLATE_TMP_CHANNEL_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PLATE_TMP_CHANNEL_GetValue()           PORTAbits.RA2
#define PLATE_TMP_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PLATE_TMP_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PLATE_TMP_CHANNEL_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PLATE_TMP_CHANNEL_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PLATE_TMP_CHANNEL_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PLATE_TMP_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PLATE_TMP_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define PLATE_TMP_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set SOIL_TMP_CHANNEL aliases
#define SOIL_TMP_CHANNEL_TRIS                 TRISAbits.TRISA3
#define SOIL_TMP_CHANNEL_LAT                  LATAbits.LATA3
#define SOIL_TMP_CHANNEL_PORT                 PORTAbits.RA3
#define SOIL_TMP_CHANNEL_WPU                  WPUAbits.WPUA3
#define SOIL_TMP_CHANNEL_OD                   ODCONAbits.ODCA3
#define SOIL_TMP_CHANNEL_ANS                  ANSELAbits.ANSELA3
#define SOIL_TMP_CHANNEL_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SOIL_TMP_CHANNEL_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SOIL_TMP_CHANNEL_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SOIL_TMP_CHANNEL_GetValue()           PORTAbits.RA3
#define SOIL_TMP_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SOIL_TMP_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SOIL_TMP_CHANNEL_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SOIL_TMP_CHANNEL_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define SOIL_TMP_CHANNEL_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define SOIL_TMP_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define SOIL_TMP_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define SOIL_TMP_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LED_INTERNAL_PIN aliases
#define LED_INTERNAL_PIN_TRIS                 TRISAbits.TRISA4
#define LED_INTERNAL_PIN_LAT                  LATAbits.LATA4
#define LED_INTERNAL_PIN_PORT                 PORTAbits.RA4
#define LED_INTERNAL_PIN_WPU                  WPUAbits.WPUA4
#define LED_INTERNAL_PIN_OD                   ODCONAbits.ODCA4
#define LED_INTERNAL_PIN_ANS                  ANSELAbits.ANSELA4
#define LED_INTERNAL_PIN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_INTERNAL_PIN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_INTERNAL_PIN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_INTERNAL_PIN_GetValue()           PORTAbits.RA4
#define LED_INTERNAL_PIN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_INTERNAL_PIN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_INTERNAL_PIN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_INTERNAL_PIN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_INTERNAL_PIN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_INTERNAL_PIN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_INTERNAL_PIN_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED_INTERNAL_PIN_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED_PLATE_PIN aliases
#define LED_PLATE_PIN_TRIS                 TRISAbits.TRISA5
#define LED_PLATE_PIN_LAT                  LATAbits.LATA5
#define LED_PLATE_PIN_PORT                 PORTAbits.RA5
#define LED_PLATE_PIN_WPU                  WPUAbits.WPUA5
#define LED_PLATE_PIN_OD                   ODCONAbits.ODCA5
#define LED_PLATE_PIN_ANS                  ANSELAbits.ANSELA5
#define LED_PLATE_PIN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_PLATE_PIN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_PLATE_PIN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_PLATE_PIN_GetValue()           PORTAbits.RA5
#define LED_PLATE_PIN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_PLATE_PIN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_PLATE_PIN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_PLATE_PIN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_PLATE_PIN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_PLATE_PIN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_PLATE_PIN_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_PLATE_PIN_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set DIGIT3_PIN aliases
#define DIGIT3_PIN_TRIS                 TRISAbits.TRISA6
#define DIGIT3_PIN_LAT                  LATAbits.LATA6
#define DIGIT3_PIN_PORT                 PORTAbits.RA6
#define DIGIT3_PIN_WPU                  WPUAbits.WPUA6
#define DIGIT3_PIN_OD                   ODCONAbits.ODCA6
#define DIGIT3_PIN_ANS                  ANSELAbits.ANSELA6
#define DIGIT3_PIN_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DIGIT3_PIN_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DIGIT3_PIN_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DIGIT3_PIN_GetValue()           PORTAbits.RA6
#define DIGIT3_PIN_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DIGIT3_PIN_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define DIGIT3_PIN_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define DIGIT3_PIN_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define DIGIT3_PIN_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define DIGIT3_PIN_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define DIGIT3_PIN_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define DIGIT3_PIN_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set LED_SET_PIN aliases
#define LED_SET_PIN_TRIS                 TRISAbits.TRISA7
#define LED_SET_PIN_LAT                  LATAbits.LATA7
#define LED_SET_PIN_PORT                 PORTAbits.RA7
#define LED_SET_PIN_WPU                  WPUAbits.WPUA7
#define LED_SET_PIN_OD                   ODCONAbits.ODCA7
#define LED_SET_PIN_ANS                  ANSELAbits.ANSELA7
#define LED_SET_PIN_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_SET_PIN_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_SET_PIN_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_SET_PIN_GetValue()           PORTAbits.RA7
#define LED_SET_PIN_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_SET_PIN_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED_SET_PIN_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED_SET_PIN_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED_SET_PIN_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED_SET_PIN_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED_SET_PIN_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LED_SET_PIN_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set SEGE_PIN aliases
#define SEGE_PIN_TRIS                 TRISBbits.TRISB0
#define SEGE_PIN_LAT                  LATBbits.LATB0
#define SEGE_PIN_PORT                 PORTBbits.RB0
#define SEGE_PIN_WPU                  WPUBbits.WPUB0
#define SEGE_PIN_OD                   ODCONBbits.ODCB0
#define SEGE_PIN_ANS                  ANSELBbits.ANSELB0
#define SEGE_PIN_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SEGE_PIN_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SEGE_PIN_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SEGE_PIN_GetValue()           PORTBbits.RB0
#define SEGE_PIN_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SEGE_PIN_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SEGE_PIN_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SEGE_PIN_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SEGE_PIN_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SEGE_PIN_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SEGE_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define SEGE_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set SEGDP_PIN aliases
#define SEGDP_PIN_TRIS                 TRISBbits.TRISB1
#define SEGDP_PIN_LAT                  LATBbits.LATB1
#define SEGDP_PIN_PORT                 PORTBbits.RB1
#define SEGDP_PIN_WPU                  WPUBbits.WPUB1
#define SEGDP_PIN_OD                   ODCONBbits.ODCB1
#define SEGDP_PIN_ANS                  ANSELBbits.ANSELB1
#define SEGDP_PIN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SEGDP_PIN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SEGDP_PIN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SEGDP_PIN_GetValue()           PORTBbits.RB1
#define SEGDP_PIN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SEGDP_PIN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SEGDP_PIN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SEGDP_PIN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SEGDP_PIN_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SEGDP_PIN_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SEGDP_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SEGDP_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set SEGD_PIN aliases
#define SEGD_PIN_TRIS                 TRISBbits.TRISB2
#define SEGD_PIN_LAT                  LATBbits.LATB2
#define SEGD_PIN_PORT                 PORTBbits.RB2
#define SEGD_PIN_WPU                  WPUBbits.WPUB2
#define SEGD_PIN_OD                   ODCONBbits.ODCB2
#define SEGD_PIN_ANS                  ANSELBbits.ANSELB2
#define SEGD_PIN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SEGD_PIN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SEGD_PIN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SEGD_PIN_GetValue()           PORTBbits.RB2
#define SEGD_PIN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SEGD_PIN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SEGD_PIN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SEGD_PIN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SEGD_PIN_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SEGD_PIN_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SEGD_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define SEGD_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SEGC_PIN aliases
#define SEGC_PIN_TRIS                 TRISBbits.TRISB3
#define SEGC_PIN_LAT                  LATBbits.LATB3
#define SEGC_PIN_PORT                 PORTBbits.RB3
#define SEGC_PIN_WPU                  WPUBbits.WPUB3
#define SEGC_PIN_OD                   ODCONBbits.ODCB3
#define SEGC_PIN_ANS                  ANSELBbits.ANSELB3
#define SEGC_PIN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SEGC_PIN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SEGC_PIN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SEGC_PIN_GetValue()           PORTBbits.RB3
#define SEGC_PIN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SEGC_PIN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SEGC_PIN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SEGC_PIN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SEGC_PIN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SEGC_PIN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SEGC_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SEGC_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SEGG_PIN aliases
#define SEGG_PIN_TRIS                 TRISBbits.TRISB4
#define SEGG_PIN_LAT                  LATBbits.LATB4
#define SEGG_PIN_PORT                 PORTBbits.RB4
#define SEGG_PIN_WPU                  WPUBbits.WPUB4
#define SEGG_PIN_OD                   ODCONBbits.ODCB4
#define SEGG_PIN_ANS                  ANSELBbits.ANSELB4
#define SEGG_PIN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SEGG_PIN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SEGG_PIN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SEGG_PIN_GetValue()           PORTBbits.RB4
#define SEGG_PIN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SEGG_PIN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SEGG_PIN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SEGG_PIN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SEGG_PIN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SEGG_PIN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SEGG_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SEGG_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SEGB_PIN aliases
#define SEGB_PIN_TRIS                 TRISBbits.TRISB5
#define SEGB_PIN_LAT                  LATBbits.LATB5
#define SEGB_PIN_PORT                 PORTBbits.RB5
#define SEGB_PIN_WPU                  WPUBbits.WPUB5
#define SEGB_PIN_OD                   ODCONBbits.ODCB5
#define SEGB_PIN_ANS                  ANSELBbits.ANSELB5
#define SEGB_PIN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SEGB_PIN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SEGB_PIN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SEGB_PIN_GetValue()           PORTBbits.RB5
#define SEGB_PIN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SEGB_PIN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SEGB_PIN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SEGB_PIN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SEGB_PIN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SEGB_PIN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SEGB_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SEGB_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set SEGF_PIN aliases
#define SEGF_PIN_TRIS                 TRISBbits.TRISB6
#define SEGF_PIN_LAT                  LATBbits.LATB6
#define SEGF_PIN_PORT                 PORTBbits.RB6
#define SEGF_PIN_WPU                  WPUBbits.WPUB6
#define SEGF_PIN_OD                   ODCONBbits.ODCB6
#define SEGF_PIN_ANS                  ANSELBbits.ANSELB6
#define SEGF_PIN_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SEGF_PIN_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SEGF_PIN_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SEGF_PIN_GetValue()           PORTBbits.RB6
#define SEGF_PIN_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SEGF_PIN_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SEGF_PIN_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SEGF_PIN_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SEGF_PIN_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SEGF_PIN_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SEGF_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define SEGF_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set SEGA_PIN aliases
#define SEGA_PIN_TRIS                 TRISBbits.TRISB7
#define SEGA_PIN_LAT                  LATBbits.LATB7
#define SEGA_PIN_PORT                 PORTBbits.RB7
#define SEGA_PIN_WPU                  WPUBbits.WPUB7
#define SEGA_PIN_OD                   ODCONBbits.ODCB7
#define SEGA_PIN_ANS                  ANSELBbits.ANSELB7
#define SEGA_PIN_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SEGA_PIN_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SEGA_PIN_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SEGA_PIN_GetValue()           PORTBbits.RB7
#define SEGA_PIN_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SEGA_PIN_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SEGA_PIN_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SEGA_PIN_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SEGA_PIN_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SEGA_PIN_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SEGA_PIN_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define SEGA_PIN_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set DIGIT2_PIN aliases
#define DIGIT2_PIN_TRIS                 TRISCbits.TRISC0
#define DIGIT2_PIN_LAT                  LATCbits.LATC0
#define DIGIT2_PIN_PORT                 PORTCbits.RC0
#define DIGIT2_PIN_WPU                  WPUCbits.WPUC0
#define DIGIT2_PIN_OD                   ODCONCbits.ODCC0
#define DIGIT2_PIN_ANS                  ANSELCbits.ANSELC0
#define DIGIT2_PIN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DIGIT2_PIN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DIGIT2_PIN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DIGIT2_PIN_GetValue()           PORTCbits.RC0
#define DIGIT2_PIN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DIGIT2_PIN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DIGIT2_PIN_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DIGIT2_PIN_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DIGIT2_PIN_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define DIGIT2_PIN_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define DIGIT2_PIN_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define DIGIT2_PIN_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set DIGIT1_PIN aliases
#define DIGIT1_PIN_TRIS                 TRISCbits.TRISC1
#define DIGIT1_PIN_LAT                  LATCbits.LATC1
#define DIGIT1_PIN_PORT                 PORTCbits.RC1
#define DIGIT1_PIN_WPU                  WPUCbits.WPUC1
#define DIGIT1_PIN_OD                   ODCONCbits.ODCC1
#define DIGIT1_PIN_ANS                  ANSELCbits.ANSELC1
#define DIGIT1_PIN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DIGIT1_PIN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DIGIT1_PIN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DIGIT1_PIN_GetValue()           PORTCbits.RC1
#define DIGIT1_PIN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DIGIT1_PIN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DIGIT1_PIN_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DIGIT1_PIN_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DIGIT1_PIN_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define DIGIT1_PIN_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define DIGIT1_PIN_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define DIGIT1_PIN_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set REALAY_PIN aliases
#define REALAY_PIN_TRIS                 TRISDbits.TRISD0
#define REALAY_PIN_LAT                  LATDbits.LATD0
#define REALAY_PIN_PORT                 PORTDbits.RD0
#define REALAY_PIN_WPU                  WPUDbits.WPUD0
#define REALAY_PIN_OD                   ODCONDbits.ODCD0
#define REALAY_PIN_ANS                  ANSELDbits.ANSELD0
#define REALAY_PIN_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define REALAY_PIN_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define REALAY_PIN_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define REALAY_PIN_GetValue()           PORTDbits.RD0
#define REALAY_PIN_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define REALAY_PIN_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define REALAY_PIN_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define REALAY_PIN_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define REALAY_PIN_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define REALAY_PIN_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define REALAY_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define REALAY_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set ISOURCE1_PIN aliases
#define ISOURCE1_PIN_TRIS                 TRISDbits.TRISD1
#define ISOURCE1_PIN_LAT                  LATDbits.LATD1
#define ISOURCE1_PIN_PORT                 PORTDbits.RD1
#define ISOURCE1_PIN_WPU                  WPUDbits.WPUD1
#define ISOURCE1_PIN_OD                   ODCONDbits.ODCD1
#define ISOURCE1_PIN_ANS                  ANSELDbits.ANSELD1
#define ISOURCE1_PIN_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define ISOURCE1_PIN_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define ISOURCE1_PIN_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define ISOURCE1_PIN_GetValue()           PORTDbits.RD1
#define ISOURCE1_PIN_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define ISOURCE1_PIN_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define ISOURCE1_PIN_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define ISOURCE1_PIN_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define ISOURCE1_PIN_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define ISOURCE1_PIN_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define ISOURCE1_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define ISOURCE1_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set ISOURCE2_PIN aliases
#define ISOURCE2_PIN_TRIS                 TRISDbits.TRISD2
#define ISOURCE2_PIN_LAT                  LATDbits.LATD2
#define ISOURCE2_PIN_PORT                 PORTDbits.RD2
#define ISOURCE2_PIN_WPU                  WPUDbits.WPUD2
#define ISOURCE2_PIN_OD                   ODCONDbits.ODCD2
#define ISOURCE2_PIN_ANS                  ANSELDbits.ANSELD2
#define ISOURCE2_PIN_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define ISOURCE2_PIN_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define ISOURCE2_PIN_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define ISOURCE2_PIN_GetValue()           PORTDbits.RD2
#define ISOURCE2_PIN_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define ISOURCE2_PIN_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define ISOURCE2_PIN_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define ISOURCE2_PIN_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define ISOURCE2_PIN_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define ISOURCE2_PIN_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define ISOURCE2_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define ISOURCE2_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set ROTARY_A_PIN aliases
#define ROTARY_A_PIN_TRIS                 TRISDbits.TRISD4
#define ROTARY_A_PIN_LAT                  LATDbits.LATD4
#define ROTARY_A_PIN_PORT                 PORTDbits.RD4
#define ROTARY_A_PIN_WPU                  WPUDbits.WPUD4
#define ROTARY_A_PIN_OD                   ODCONDbits.ODCD4
#define ROTARY_A_PIN_ANS                  ANSELDbits.ANSELD4
#define ROTARY_A_PIN_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define ROTARY_A_PIN_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define ROTARY_A_PIN_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define ROTARY_A_PIN_GetValue()           PORTDbits.RD4
#define ROTARY_A_PIN_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define ROTARY_A_PIN_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define ROTARY_A_PIN_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define ROTARY_A_PIN_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define ROTARY_A_PIN_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define ROTARY_A_PIN_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define ROTARY_A_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define ROTARY_A_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set ROTARY_C_PIN aliases
#define ROTARY_C_PIN_TRIS                 TRISDbits.TRISD5
#define ROTARY_C_PIN_LAT                  LATDbits.LATD5
#define ROTARY_C_PIN_PORT                 PORTDbits.RD5
#define ROTARY_C_PIN_WPU                  WPUDbits.WPUD5
#define ROTARY_C_PIN_OD                   ODCONDbits.ODCD5
#define ROTARY_C_PIN_ANS                  ANSELDbits.ANSELD5
#define ROTARY_C_PIN_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define ROTARY_C_PIN_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define ROTARY_C_PIN_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define ROTARY_C_PIN_GetValue()           PORTDbits.RD5
#define ROTARY_C_PIN_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define ROTARY_C_PIN_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define ROTARY_C_PIN_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define ROTARY_C_PIN_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define ROTARY_C_PIN_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define ROTARY_C_PIN_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define ROTARY_C_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define ROTARY_C_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set ROTARY_SWITCH_PIN aliases
#define ROTARY_SWITCH_PIN_TRIS                 TRISDbits.TRISD6
#define ROTARY_SWITCH_PIN_LAT                  LATDbits.LATD6
#define ROTARY_SWITCH_PIN_PORT                 PORTDbits.RD6
#define ROTARY_SWITCH_PIN_WPU                  WPUDbits.WPUD6
#define ROTARY_SWITCH_PIN_OD                   ODCONDbits.ODCD6
#define ROTARY_SWITCH_PIN_ANS                  ANSELDbits.ANSELD6
#define ROTARY_SWITCH_PIN_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define ROTARY_SWITCH_PIN_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define ROTARY_SWITCH_PIN_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define ROTARY_SWITCH_PIN_GetValue()           PORTDbits.RD6
#define ROTARY_SWITCH_PIN_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define ROTARY_SWITCH_PIN_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define ROTARY_SWITCH_PIN_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define ROTARY_SWITCH_PIN_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define ROTARY_SWITCH_PIN_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define ROTARY_SWITCH_PIN_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define ROTARY_SWITCH_PIN_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define ROTARY_SWITCH_PIN_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set LED_SOIL_PIN aliases
#define LED_SOIL_PIN_TRIS                 TRISEbits.TRISE0
#define LED_SOIL_PIN_LAT                  LATEbits.LATE0
#define LED_SOIL_PIN_PORT                 PORTEbits.RE0
#define LED_SOIL_PIN_WPU                  WPUEbits.WPUE0
#define LED_SOIL_PIN_OD                   ODCONEbits.ODCE0
#define LED_SOIL_PIN_ANS                  ANSELEbits.ANSELE0
#define LED_SOIL_PIN_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED_SOIL_PIN_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED_SOIL_PIN_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED_SOIL_PIN_GetValue()           PORTEbits.RE0
#define LED_SOIL_PIN_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED_SOIL_PIN_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED_SOIL_PIN_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED_SOIL_PIN_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED_SOIL_PIN_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED_SOIL_PIN_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED_SOIL_PIN_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LED_SOIL_PIN_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set LED_AMBIENT_PIN aliases
#define LED_AMBIENT_PIN_TRIS                 TRISEbits.TRISE1
#define LED_AMBIENT_PIN_LAT                  LATEbits.LATE1
#define LED_AMBIENT_PIN_PORT                 PORTEbits.RE1
#define LED_AMBIENT_PIN_WPU                  WPUEbits.WPUE1
#define LED_AMBIENT_PIN_OD                   ODCONEbits.ODCE1
#define LED_AMBIENT_PIN_ANS                  ANSELEbits.ANSELE1
#define LED_AMBIENT_PIN_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED_AMBIENT_PIN_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED_AMBIENT_PIN_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED_AMBIENT_PIN_GetValue()           PORTEbits.RE1
#define LED_AMBIENT_PIN_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED_AMBIENT_PIN_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED_AMBIENT_PIN_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define LED_AMBIENT_PIN_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define LED_AMBIENT_PIN_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define LED_AMBIENT_PIN_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define LED_AMBIENT_PIN_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define LED_AMBIENT_PIN_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set LED_READ_PIN aliases
#define LED_READ_PIN_TRIS                 TRISEbits.TRISE2
#define LED_READ_PIN_LAT                  LATEbits.LATE2
#define LED_READ_PIN_PORT                 PORTEbits.RE2
#define LED_READ_PIN_WPU                  WPUEbits.WPUE2
#define LED_READ_PIN_OD                   ODCONEbits.ODCE2
#define LED_READ_PIN_ANS                  ANSELEbits.ANSELE2
#define LED_READ_PIN_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_READ_PIN_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_READ_PIN_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_READ_PIN_GetValue()           PORTEbits.RE2
#define LED_READ_PIN_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_READ_PIN_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_READ_PIN_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LED_READ_PIN_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LED_READ_PIN_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define LED_READ_PIN_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define LED_READ_PIN_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define LED_READ_PIN_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/