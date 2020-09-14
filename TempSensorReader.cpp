#include "TempSensorReader.h"

TempSensorReader::TempSensorReader(int sensorpin)
{
    sensorPin = sensorpin;

    inputVoltage = 1023.0;
}

float TempSensorReader::GetTemp() {
    
}

float TempSensorReader::ReadResistance() {
    float reading = analogRead(sensorPin);
    return reading;
}

float TempSensorReader::KelvinToCelcius(float temp) {
    return temp-273.15;
}

float TempSensorReader::CalculateTemp(float resistance) {
    //return 1.0/((A)+(B*log(resistance))+(self.C*power(log(resistance),3)));
    logR = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));}

float TempSensorReader::CalculateResistance(float measuredVoltage) {
    return knownResistance*((inputVoltage/measuredVoltage)-1);
}