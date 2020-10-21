#include "MapSensorReader.h"

MapSensorReader::MapSensorReader(int sensorpin)
{
    SensorPin = sensorpin;
}

//returns map sensor value in bar
float MapSensorReader::GetMapReading() {
    float boost;
    
    boost = ReadPin();
    boost = CalculateVoltage(boost);
    boost = CalculatePressureReading(boost);
    return KpaToBar(boost);
}

float MapSensorReader::ReadPin() {
    float reading = analogRead(SensorPin);
    return reading;
}

float MapSensorReader::CalculateVoltage(float mapSensorValue) {
    return mapSensorValue * (5.0 / 1023.0);
}

float MapSensorReader::CalculatePressureReading(float mapSensorVoltage) {
    return 65.5f*mapSensorVoltage + 0.5;
}

float MapSensorReader::KpaToBar(float mapSensorPressure) {
    return mapSensorPressure/100.0f;
}