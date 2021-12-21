#include "CoolantTempSensorMock.h"

CoolantTempSensorMock::CoolantTempSensorMock(int Mode) {
	if (Mode == 0) { 
		//start from room temp ~20C
		currentTemp = 20.0f;
	} else if (Mode == 1) { 
		//start from almost operating temp ~60C
		currentTemp = 60.0f;
	} else if (Mode == 2) { 
		//start from overheating temp ~ 95C
		currentTemp = 95.0f;
	} else {
		currentTemp  = 0.0f;
	}
}

float CoolantTempSensorMock::GetValue() {
	return currentTemp;
}

void CoolantTempSensorMock::updateTemp() {
	
}
