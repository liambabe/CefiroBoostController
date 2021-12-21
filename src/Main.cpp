#include "Main.h"

Main::Main(Adafruit_BluefruitLE_UART* ble, bool debugMode, int coolantTempPin, int FanPin, int MapPin, int AirTempPin)
{
	if (debugMode == 1) {
		InitializeDebug();
	} else {
		InitializeProd(coolantTempPin, FanPin, MapPin, AirTempPin);
	}

  bluetoothCommunicator = ble;

	mapReading          = 0.0f;
	intakeTempReading   = 0.0f;
	coolantTempReading  = 0.0f;
}

void Main::InitializeDebug() {
  coolantTempSensorReader = new CoolantTempSensorMock(0);
}

void Main::InitializeProd(int coolantTempPin, int FanPin, int MapPin, int AirTempPin) {
  coolantTempSensorReader = new TempSensorReader(coolantTempPin, 300, 1.170050316e-03, 2.792152116e-04, 0.5816839769e-07, "down");
  fanController = new FanController(FanPin);
  tMapSensor->mapSensorReader = new MapSensorReader(MapPin);
  tMapSensor->airIntakeSensorReader = new TempSensorReader(AirTempPin, 1000, 1.247757853e-03, 2.698625133e-04, 1.073910146e-07, "up");
}

void Main::tick() {
  char dataStr[24];

  coolantTempReading = coolantTempSensorReader->GetValue();

  mergeData(dataStr);
  bluetoothCommunicator->println(dataStr);    
}

void Main::mergeData(char* mergedData) {

  char SensorReadings[24];
  char coolantCharReading[6];
  //char MapCharReading[6];
  //char airCharReading[6];

  dtostrf(coolantTempReading, 5, 2, coolantCharReading);
  //dtostrf(mapReading, 4, 2, MapCharReading);
  //dtostrf(intakeTempReading, 5, 2, airCharReading);

  strcpy(SensorReadings, coolantCharReading);
  strcat(SensorReadings, ",");
  //strcat(SensorReadings, MapCharReading);
  //strcat(SensorReadings, ",");
  //strcat(SensorReadings, airCharReading);
  //strcat(SensorReadings, ",");
  strcat(SensorReadings, "off");
  strcat(SensorReadings, "#");

  for (int i = 0; i < 24; i++) {
    mergedData[i] = SensorReadings[i];
  }

}