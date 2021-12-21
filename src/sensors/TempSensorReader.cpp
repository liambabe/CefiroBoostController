#include "TempSensorReader.h"

TempSensorReader::TempSensorReader(int sensorpin, float seriesresistance, float a, float b, float c, char* resistorposition)
{
    sensorPin = sensorpin;
    seriesResistance = seriesresistance;
    strcpy(ResistorPosition, resistorposition);

    A = a;
    B = b;
    C = c;

    inputVoltage = 1023.0;
}

float TempSensorReader::GetValue() {
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
  
    float reading;
    reading = (inputVoltage / measuredVoltage)  - 1;
    
    if (strcmp(ResistorPosition, "up") == 0) {
      reading = seriesResistance / reading;
    } else if (strcmp(ResistorPosition, "down") == 0) {
      reading = seriesResistance * reading;
    }
    
    return reading;
}
