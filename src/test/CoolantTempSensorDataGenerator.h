#ifndef CoolantTempSensorDataGenerator_h
#define CoolantTempSensorDataGenerator_h

#include "Arduino.h"
#include "../interfaces/SensorReader.h"

class CoolantTempSensorDataGenerator: public SensorReader
{
    public:
        CoolantTempSensorDataGenerator(int Mode);
        float GetValue();
    private:
        float currentTemp;
        void updateTemp();
};

#endif