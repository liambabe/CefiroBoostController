#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerialCon(2,3);

int FanPin = 13;
char blueToothVal; //value sent over via bluetooth
    
void setup() {

  pinMode(FanPin, OUTPUT);
  bluetoothSerialCon.begin(9600);
  
}

void loop() {

  if (bluetoothSerialCon.available()) { //check if data avaliable
    blueToothVal = bluetoothSerialCon.read(); 
  }

  if (blueToothVal == 'O') {
    digitalWrite(FanPin, HIGH);
  } else if (blueToothVal == 'F') {
    digitalWrite(FanPin, LOW);             
  }
  
  delay(1000);

}
