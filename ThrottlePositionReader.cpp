#include "ThrottlePositionReader.h"

ThrottlePositionReader::ThrottlePositionReader(int sensorpin)
{
    sensorPin = sensorpin;
}

float ThrottlePositionReader::GetPosition() {
    return 0.0f;
}

float ThrottlePositionReader::ReadPin() {
    float reading = analogRead(sensorPin);
    return reading;
}