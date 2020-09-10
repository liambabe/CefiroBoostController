#ifndef FanController_h
#define FanController_h

#include "Arduino.h"

class FanController
{
    public:
        FanController(int outputpin);
        void TurnOnFan();
        void TurnOffFan();
        bool GetFanStatus();
    private:
        bool _FanStatus;
        int _OutputPin;
};

#endif