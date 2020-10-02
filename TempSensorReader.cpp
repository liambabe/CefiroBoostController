#include "TempSensorReader.h"

TempSensorReader::TempSensorReader(int sensorpin, float seriesresistance, float a, float b, float c)
{
    sensorPin = sensorpin;
    seriesResistance = seriesresistance;

    A = a;
    B = b;
    C = c;

    inputVoltage = 1023.0;
}

float TempSensorReader::GetTemp() {
    float temp;
    
    temp = ReadPin();
    temp = CalculateResistance(temp);
    temp = CalculateTemp(temp);
    return KelvinToCelcius(temp);
}

float TempSensorReader::ReadPin() {
    float reading = analogRead(sensorPin);
    return reading;
}

float TempSensorReader::KelvinToCelcius(float temp) {
    return temp-273.15;
}

float TempSensorReader::CalculateTemp(float resistanceReading) {
    return (1.0 / (A + B*log(resistanceReading) + C*log(resistanceReading)*log(resistanceReading)*log(resistanceReading)));
}

float TempSensorReader::CalculateResistance(float measuredVoltage) {
    return seriesResistance*((inputVoltage/measuredVoltage)-1);
}