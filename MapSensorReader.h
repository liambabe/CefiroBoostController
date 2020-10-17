#ifndef MapSensorReader_h
#define MapSensorReader_h

#include "Arduino.h"

class MapSensorReader
{
    public:
        MapSensorReader(int sensorpin);
        float GetMapReading();
    private:
        float ReadPin();
        float CalculateVoltage(float mapSensorValue);
        float CalculatePressureReading(float mapSensorVoltage);
        float KpaToBar(float mapSensorPressure);
        int SensorPin;
};

#endif