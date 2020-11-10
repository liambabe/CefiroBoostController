#ifndef ThrottlePositionReader_h
#define ThrottlePositionReader_h

#include "Arduino.h"

class ThrottlePositionReader
{
    public:
        ThrottlePositionReader(int sensorpin);
        float GetPosition();
    private:
        float ReadPin();
        int sensorPin;

};

#endif
