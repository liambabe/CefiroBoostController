#ifndef Main_h
#define Main_h

#include "Arduino.h"


#include "interfaces/SensorReader.h"
#include "sensors/TempSensorReader.h"
#include "test/CoolantTempSensorDataGenerator.h"

class Main
{
    public:
        Main(bool DEBUG_MODE, int CoolantTempPin);
        SensorReader *coolantTempSensorReader;
    private:
        void InitializeDebug();
        void InitializeProd(int CoolantTempPin);
};

#endif
