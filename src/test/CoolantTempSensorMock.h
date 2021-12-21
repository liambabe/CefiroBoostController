#ifndef CoolantTempSensorMock_h
#define CoolantTempSensorMock_h

#include "Arduino.h"
#include "../interfaces/SensorReader.h"

class CoolantTempSensorMock: public SensorReader
{
    public:
        CoolantTempSensorMock(int Mode);
        float GetValue();
    private:
        float currentTemp;
        void updateTemp();
};

#endif