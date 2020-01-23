/* 
 * File:   rotaryEncoderDriver.h
 * Author: marko
 *
 * Created on January 23, 2020, 10:56 PM
 */

#ifndef ROTARYENCODERDRIVER_H
#define	ROTARYENCODERDRIVER_H

int previousSwitchState = 0;
int previousA1State = 0;
int previousC1State = 1; 


int getEncoderChange();
int isSwitchPressed();

void setSwitchState(int state);
void setEncoderState(int state);



#ifdef	__cplusplus
extern "C" {
#endif

    

#ifdef	__cplusplus
}
#endif

#endif	/* ROTARYENCODERDRIVER_H */

