#ifndef CoolantTempSensorDataGenerator_h
#define CoolantTempSensorDataGenerator_h

#include "Arduino.h"

class CoolantTempSensorDataGenerator
{
    public:
        CoolantTempSensorDataGenerator(int Mode);
        float GetTemp();
    private:
        float currentTemp;
        void updateTemp();
};

#endif
