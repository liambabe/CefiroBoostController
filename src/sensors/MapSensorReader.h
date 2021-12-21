#ifndef MapSensorReader_h
#define MapSensorReader_h

#include "Arduino.h"

#include "../interfaces/SensorReader.h"

class MapSensorReader: public SensorReader
{
    public:
        MapSensorReader(int sensorpin);
        float GetValue();
    private:
        float ReadPin();
        float CalculateVoltage(float mapSensorValue);
        float CalculatePressureReading(float mapSensorVoltage);
        float KpaToBar(float mapSensorPressure);
        int SensorPin;
};

#endif