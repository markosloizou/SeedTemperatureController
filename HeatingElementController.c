#include "HeatingElementController.h"

static int soilTgoal, internalTcutoff, plateTcutoff; 


void HC_setMaxInternalTemp(int t)
{
    internalTcutoff = t; 
}


void HC_setMaxPlateTemp(int t)
{
    plateTcutoff = t;
}


void HC_setSoilTempGoil(int t)
{
    soilTgoal = t;
}

void HC_regulateTemperature(int soilT, int plateT, int internalT)
{
    
}