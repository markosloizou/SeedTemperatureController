/* 
 * File:   HeatingElementController.h
 * Author: marko
 *
 * Created on 24 January 2020, 10:52
 */

#ifndef HEATINGELEMENTCONTROLLER_H
#define	HEATINGELEMENTCONTROLLER_H

void HC_setMaxInternalTemp(int t);
void HC_setMaxPlateTemp(int t);
void HC_setSoilTempGoil(int t);

void HC_initialize();
void HC_regulateTemperature(int soilT, int plateT, int internalT);

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* HEATINGELEMENTCONTROLLER_H */

