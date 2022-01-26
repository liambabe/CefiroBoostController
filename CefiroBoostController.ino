#include <SoftwareSerial.h>
#include <math.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"
#include <Arduino.h>

#include "src/Main.h"

#define BUFSIZE                   128   // Size of the read buffer for incoming data
#define VERBOSE_MODE              true
// SOFTWARE UART SETTINGS
#define BLUEFRUIT_SWUART_RXD_PIN  9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN  10   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN    11   // Required for software serial!
#define BLUEFRUIT_UART_RTS_PIN    -1   // Optional, set to -1 if unused
#define BLUEFRUIT_UART_MODE_PIN   -1    // Set to -1 if unused
// SOFTWARE SPECIFIC SETTINGS
#define DEBUG_MODE                1
#define RADIATOR_FAN_PIN          13
#define MAP_SENSOR_PIN            A0
#define AIR_TEMP_SENSOR_PIN       A1
#define COOLANT_TEMP_SENSOR_PIN   A2

SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);
Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN, BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

Main mainClass(&ble, DEBUG_MODE, COOLANT_TEMP_SENSOR_PIN, RADIATOR_FAN_PIN, MAP_SENSOR_PIN, AIR_TEMP_SENSOR_PIN);

void setup() {

  pinMode(RADIATOR_FAN_PIN, OUTPUT);
  pinMode(MAP_SENSOR_PIN, INPUT);
  pinMode(AIR_TEMP_SENSOR_PIN, INPUT);
  pinMode(COOLANT_TEMP_SENSOR_PIN, INPUT);

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

void loop() {

  mainClass.tick();
  delay(1000);

}
