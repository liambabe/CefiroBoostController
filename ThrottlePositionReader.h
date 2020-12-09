#ifndef ThrottlePositionReader_h
#define ThrottlePositionReader_h

#include "Arduino.h"

class ThrottlePositionReader
{
    public:
        ThrottlePositionReader(int sensorpin);
        float GetPosition();
        float GetThrottleData();
    private:
        float ReadPin();
        int sensorPin;

};

#endif
