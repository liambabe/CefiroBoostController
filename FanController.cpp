#include "FanController.h"

FanController::FanController(int outputpin)
{
    _OutputPin = outputpin;
    _FanStatus = false;
}

bool FanController::GetFanStatus() 
{
    return _FanStatus;
} 

void FanController::TurnOnFan() 
{
    if (GetFanStatus()) { return;}

    digitalWrite(_OutputPin, HIGH);
    _FanStatus = true;
}

void FanController::TurnOffFan() 
{
    if (!GetFanStatus()) { return;}

    digitalWrite(_OutputPin, LOW);
    _FanStatus = false;
}