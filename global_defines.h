/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GLOBAL_DEFINES_H
#define	GLOBAL_DEFINES_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// ADC channels for thermometers
#define AMBIENT_TMP_CHANNEL 000
#define INTERNAL_TMP_CHANNEL 001
#define PLATE_TMP_CHANNEL 010
#define SOIL_TMP_CHANNEL 011

//relay 
#define RELAY_PIN 0
#define RELAY_PORT LATD

//current sources
#define ISOURCE1_PIN 1
#define ISOURCE1_PORT LATD
#define ISOURCE2_PIN 2
#define ISOURCE2_PORT LATD

//rotary encoder
#define ROTARY_SWITCH_PIN 6
#define ROTARY_SWITCH_PORT PORTD
#define ROTARY_A_PIN 4
#define ROTARAY_A_PORT PORTD
#define ROTARY_C_PIN 5
#define ROTARAY_C_PORT PORTD

#define STABLE_SWITCH_COUNT 50 /* 50 ms with sampling at 1000Hz*/
#define STABLE_ENCODER_COUNT 10 // 10ms for encoder since it can handle higher RPM

//Indicator LEDs
#define LED_INTERNAL_PIN 4
#define LED_INTERNAL_PORT LATA
#define LED_PLATE_PIN 5
#define LED_PLATE_PORT LATA
#define LED_SOIL_PIN 0
#define LED_SOIL_PORT LATE
#define LED_AMBIENT_PIN 1
#define LED_AMBIENT_PORT LATE
#define LED_READ_PIN 2
#define LED_READ_PORT LATE
#define LED_SET_PIN 7
#define LED_SET_PORT LATA


//Segment Display

#define DIGIT1_PIN 1
#define DIGIT1_PORT LATC
#define DIGIT2_PIN 0
#define DIGIT2_PORT LATC
#define DIGIT3_PIN 6
#define DIGIT3_PORT LATA

#define SEGGMENT_DISPLAY_PORT LATB

#define SEGA_PIN 7
#define SEGA_PORT LATB
#define SEGB_PIN 5
#define SEGB_PORT LATB
#define SEGC_PIN 3
#define SEGC_PORT LATB
#define SEGD_PIN 2
#define SEGD_PORT LATB
#define SEGE_PIN 0
#define SEGE_PORT LATB
#define SEGF_PIN 6
#define SEGF_PORT LATB
#define SEGG_PIN 4
#define SEGG_PORT LATB
#define SEGDP_PIN 2
#define SEGDP_PORT LATB

//System specifications 
#define MCU_VOLTAGE 5.0



// golbal enumerations
typedef enum{SOIL , INTERNAL, PLATE, AMBIENT} sensor;
typedef enum{READ, SET, OFF} reading_state;


// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

