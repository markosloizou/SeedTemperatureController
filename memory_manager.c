#include "memory_manager.h"
#include "mcc_generated_files/memory.h"

void readSoilMax(int * temp)
{
    int t;
    t = (DATAEE_ReadByte(0) << 8) & DATAEE_ReadByte(1);
    *temp = t;        
}

void readSoilMin(int * temp)
{
     int t;
    t = (DATAEE_ReadByte(2) << 8) & DATAEE_ReadByte(3);
    *temp = t;        
}

void readPlateMax(int * temp)
{
     int t;
    t = (DATAEE_ReadByte(4) << 8) & DATAEE_ReadByte(5);
    *temp = t;        
}


void readInternalMax(int * temp)
{
     int t;
    t = (DATAEE_ReadByte(6) << 8) & DATAEE_ReadByte(7);
    *temp = t;        
}

void saveSoilMax(int * temp)
{
    DATAEE_WriteByte(0, (*temp >> 8) & 0xFF );
    DATAEE_WriteByte(1,  *temp  & 0xFF );
}

void saveSoilMin(int * temp)
{
    DATAEE_WriteByte(2, (*temp >> 8) & 0xFF );
    DATAEE_WriteByte(3,  *temp  & 0xFF );
}

void savePlateMax(int * temp)
{
    DATAEE_WriteByte(4, (*temp >> 8) & 0xFF );
    DATAEE_WriteByte(5,  *temp  & 0xFF );
}


void saveInternalMax(int * temp)
{
    DATAEE_WriteByte(6, (*temp >> 8) & 0xFF );
    DATAEE_WriteByte(7,  *temp  & 0xFF );
}