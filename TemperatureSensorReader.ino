//values for resistance calculation
float INPUTVOLTAGE;
float RESISTANCE;

//values for steinhart-hart calculation
float A;
float B;
float C;
    
TemperatureSensorReader ()
{
    IPUTVOLTAGE = 5; //volts
    RESISTANCE = 0; //ohms
    A = 1.250175945e-3;
    B = 2.698384119e-4;
    C = 1.040158027e-7;

float calculateResistance(float measuredVoltage) {
        return RESISTANCE*((INPUTVOLTAGE/measuredVoltage)-1);
}

float calculateTemp(float resistance) {
        //return 1.0/((A)+(B*log(resistance))+(self.C*power(log(resistance),3)));
}

    def kelvinToCelcius(float temp) {
        return temp-273.15;
}