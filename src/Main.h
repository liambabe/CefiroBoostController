#ifndef Main_h
#define Main_h

#include "Arduino.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "interfaces/SensorReader.h"
#include "sensors/TempSensorReader.h"
#include "test/CoolantTempSensorDataGenerator.h"

class Main
{
    public:
        Main(Adafruit_BluefruitLE_UART* ble, bool debugMode, int coolantTempPin);
        SensorReader *coolantTempSensorReader;
        void tick();
    private:
        void InitializeDebug();
        void InitializeProd(int coolantTempPin);
        void mergeData(char* mergedData);
        float mapReading;
        float intakeTempReading;
        float coolantTempReading;
        Adafruit_BluefruitLE_UART* bluetoothCommunicator;
};

#endif
