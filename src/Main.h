#ifndef Main_h
#define Main_h

#include "Arduino.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "controllers/FanController.h"

#include "interfaces/SensorReader.h"
#include "sensors/TempSensorReader.h"
#include "sensors/MapSensorReader.h"
#include "test/CoolantTempSensorDataGenerator.h"

class Main
{
    public:
        struct TMapSensor {
            SensorReader *mapSensorReader;
            SensorReader *airIntakeSensorReader;
        };

        Main(Adafruit_BluefruitLE_UART* ble, bool debugMode, int coolantTempPin, int FanPin, int MapPin, int AirTempPin);
        void tick();

        SensorReader *coolantTempSensorReader;
        FanController *fanController;
        TMapSensor *tMapSensor;
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
