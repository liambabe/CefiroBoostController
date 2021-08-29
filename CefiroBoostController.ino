#include <SoftwareSerial.h>
#include <math.h>

#include "FanController.h"
#include "TempSensorReader.h"
#include "MapSensorReader.h"
#include "test/CoolantTempSensorDataGenerator.h" 

SoftwareSerial bluetoothSerialCon(2,3);

int FanPin = 13;
int MapPin = A0;
int AirTempPin = A1;
int CoolantTempPin = A2;

float mapReading = 0.0f;
float intakeTempReading = 0.0f;
float coolantTempReading = 0.0f;

char blueToothVal; //value sent over via bluetooth

FanController fanController(FanPin);
TempSensorReader CoolantTempSensorReader(CoolantTempPin, 300, 1.170050316e-03, 2.792152116e-04, 0.5816839769e-07, "down");

struct TMapSensor {
  MapSensorReader mapSensorReader;
  TempSensorReader airIntakeSensorReader;
  TMapSensor() : mapSensorReader(MapPin), airIntakeSensorReader(AirTempPin, 1000, 1.247757853e-03, 2.698625133e-04, 1.073910146e-07, "up") {}
} tMapSensor;

void setup() {

  pinMode(FanPin, OUTPUT);
  pinMode(MapPin, INPUT);
  pinMode(AirTempPin, INPUT);
  pinMode(CoolantTempPin, INPUT);

  bluetoothSerialCon.begin(9600);
}

void mergeData(char* mergedData) {

  char SensorReadings[24];
  char coolantCharReading[6];
  //char MapCharReading[6];
  //char airCharReading[6];

  //dtostrf(coolantTempReading, 5, 2, coolantCharReading);
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

void loop() {

  //mapReading = tMapSensor.mapSensorReader.GetMapReading();
  //intakeTempReading = tMapSensor.airIntakeSensorReader.GetTemp();
  coolantTempReading = CoolantTempSensorReader.GetTemp();

  if (bluetoothSerialCon.available()) { //check if data avaliable
    blueToothVal = bluetoothSerialCon.read(); 
  }

  char dataStr[24];
  mergeData(dataStr);
  
  bluetoothSerialCon.write(dataStr);
  
  delay(1000);

}
