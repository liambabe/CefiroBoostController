#include <SoftwareSerial.h>
#include <math.h>

#include "FanController.h"
#include "TempSensorReader.h"
#include "MapSensorReader.h"

SoftwareSerial bluetoothSerialCon(2,3);

int FanPin = 13;
int MapPin = A0;
int AirTempPin = A1;

float mapReading = 0.0f;
float intakeTempReading = 0.0f;

char blueToothVal; //value sent over via bluetooth

FanController fanController(FanPin);

struct TMapSensor {
  MapSensorReader mapSensorReader;
  TempSensorReader airIntakeSensorReader;
  TMapSensor() : mapSensorReader(MapPin), airIntakeSensorReader(AirTempPin, 1000, 1.247757853e-03, 2.698625133e-04, 1.073910146e-07) {}
} tMapSensor;

void setup() {

  pinMode(FanPin, OUTPUT);
  pinMode(MapPin, INPUT);
  pinMode(AirTempPin, INPUT);

  bluetoothSerialCon.begin(9600);
}

void loop() {

  mapReading = tMapSensor.mapSensorReader.GetMapReading();
  intakeTempReading = tMapSensor.airIntakeSensorReader.GetTemp();

  if (bluetoothSerialCon.available()) { //check if data avaliable
    blueToothVal = bluetoothSerialCon.read(); 
  }

  if (blueToothVal == 'O') {
    fanController.TurnOnFan();
  } else if (blueToothVal == 'F') {
    fanController.TurnOffFan();         
  }

  char SensorReadings[12];
  char MapCharReading[6];
  char airCharReading[6];
  
  dtostrf(mapReading, 4, 2, MapCharReading);
  dtostrf(intakeTempReading, 5, 2, airCharReading);

  strcpy(SensorReadings, MapCharReading);
  strcat(SensorReadings, ",");
  strcat(SensorReadings, airCharReading);
  strcat(SensorReadings, "#");
  
  bluetoothSerialCon.write("80.4,24.5,1.10,on#");
  
  delay(1000);

}
