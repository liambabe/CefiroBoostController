#ifndef TempSensorReader_h
#define TempSensorReader_h

#include "Arduino.h"

class TempSensorReader
{
    public:
        TempSensorReader(int sensorpin);
        float GetTemp();
    private:
        float ReadResistance();
        float KelvinToCelcius(float temp);
        float CalculateTemp(float resistance);
        float CalculateResistance(float measuredVoltage);
        int sensorPin;
        float inputVoltage;
        float knownResistance;
        float A;
        float B;
        float C;
};

#endif
