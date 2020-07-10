
int outputPin;
bool fanStatus;

fancontroller (int outputpin)
{
    outputPin = 7;
}

bool getFanStatus() {
    return fanStatus;
} 

void TurnOnFan() {

    if (getFanStatus()) { return;}

    digitalWrite(outPin, HIGH);
    fanStatus = true;

}

void TurnOffFan() {

    if (!getFanStatus()) { return;}

    digitalWrite(outPin, LOW);
    fanStatus = false;

}