/*//Script to read a 3 bar bosch map sensor and print reading in bar to serial

int MapSensorPin = A0;    
int AirTempSensorPin = A1;

int MapSensorValue = 0; 
int AirTempSensorValue = 0; 

float MapSensorVoltage = 0.0f;

float MapReading = 0.0f;
    
void setup() {
  pinMode(MapSensorPin, INPUT);
  pinMode(AirTempSensorPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  
  MapSensorValue = analogRead(MapSensorPin);
  AirTempSensorValue = analogRead(AirTempSensorPin);

  MapSensorVoltage = MapSensorValue * (5.0 / 1023.0);

  MapReading = 65.5f*MapSensorVoltage + 0.5;

  MapReading = MapReading/100; //convert to bar

  Serial.print("Map value: ");
  Serial.println(MapReading);
  //Serial.println("Air Temp value: " + AirTempSensorValue);
  Serial.println("==========================");
  delay(1000);
}*/
