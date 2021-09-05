#include <SoftwareSerial.h>
#include <math.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"
#include <Arduino.h>

#include "FanController.h"
#include "TempSensorReader.h"
#include "MapSensorReader.h"
#include "src/test/CoolantTempSensorDataGenerator.h" 

#define BUFSIZE                        128   // Size of the read buffer for incoming data
#define VERBOSE_MODE                   true
// SOFTWARE UART SETTINGS
#define BLUEFRUIT_SWUART_RXD_PIN       9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN       10   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN         11   // Required for software serial!
#define BLUEFRUIT_UART_RTS_PIN         8   // Optional, set to -1 if unused
#define BLUEFRUIT_UART_MODE_PIN        -1    // Set to -1 if unused



SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
                      BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

int FanPin = 13;
int MapPin = A0;
int AirTempPin = A1;
int CoolantTempPin = A2;

float mapReading = 0.0f;
float intakeTempReading = 0.0f;
float coolantTempReading = 0.0f;

CoolantTempSensorDataGenerator coolantTempSensorDataGenerator(0);

//#define BLUEFRUIT_HWSERIAL_NAME           Serial1


void setup() {

  pinMode(FanPin, OUTPUT);
  pinMode(MapPin, INPUT);
  pinMode(AirTempPin, INPUT);
  pinMode(CoolantTempPin, INPUT);

while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit UriBeacon Example"));
  Serial.println(F("------------------------------------"));

/* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
  }
  Serial.println( F("OK!") );

  /* Disable command echo from Bluefruit */
  ble.echo(true);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();


}

void mergeData(char* mergedData) {

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

void loop() {

  coolantTempReading = coolantTempSensorDataGenerator.GetTemp();
  char dataStr[24];
  mergeData(dataStr);
  ble.println(dataStr);    

  delay(1000);

}
