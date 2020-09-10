#include <SoftwareSerial.h>

#include "FanController.h"

SoftwareSerial bluetoothSerialCon(2,3);

int FanPin = 12;
char blueToothVal; //value sent over via bluetooth

FanController fanController(FanPin);   

void setup() {

  pinMode(FanPin, OUTPUT);
  bluetoothSerialCon.begin(9600);
  
}

void loop() {

  if (bluetoothSerialCon.available()) { //check if data avaliable
    blueToothVal = bluetoothSerialCon.read(); 
  }

  if (blueToothVal == 'O') {
    fanController.TurnOnFan();
  } else if (blueToothVal == 'F') {
    fanController.TurnOffFan();         
  }
  
  delay(1000);

}
