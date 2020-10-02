#ifndef TempSensorReader_h
#define TempSensorReader_h

#include "Arduino.h"

class TempSensorReader
{
    public:
        TempSensorReader(int sensorpin, float seriesresistance, float a, float b, float c);
        float GetTemp();
    private:
        float ReadPin();
        float KelvinToCelcius(float temp);
        float CalculateTemp(float resistance);
        float CalculateResistance(float measuredVoltage);
        int sensorPin;
        float inputVoltage;
        float seriesResistance;
        float A;
        float B;
        float C;
};

#endif
