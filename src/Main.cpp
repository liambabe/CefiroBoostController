#include "Main.h"

Main::Main(bool DEBUG_MODE, int CoolantTempPin) {
	if (DEBUG_MODE == 1) {
		InitializeDebug();
	} else {
		InitializeProd(CoolantTempPin);
	}
}

void Main::InitializeDebug() {
	coolantTempSensorReader = new CoolantTempSensorDataGenerator(0);
}

void Main::InitializeProd(int CoolantTempPin) {
	coolantTempSensorReader = new TempSensorReader(CoolantTempPin, 300, 1.170050316e-03, 2.792152116e-04, 0.5816839769e-07, "down");
}