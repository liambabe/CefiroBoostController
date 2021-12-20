#ifndef TempSensorReader_h
#define TempSensorReader_h

#include "Arduino.h"
#include "../interfaces/SensorReader.h"

class TempSensorReader: public SensorReader
{
    public:
        TempSensorReader(int sensorpin, float seriesresistance, float a, float b, float c, char* resistorposition);
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
        char ResistorPosition[4];
};

#endif
