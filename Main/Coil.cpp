#include "Coil.h"
#include "Arduino.h"

Coil::Coil(int pinNum) : _pinNumber(pinNum) {
  pinMode(pinNum,OUTPUT);
  }

int Coil::getPinNumber() const {
    return _pinNumber;
}

void Coil::fire(OutputController& outputContoller, unsigned long duration) {
    solenoidInfo solenoidInfoTemp;
    solenoidInfoTemp.pinNumber = getPinNumber();
    solenoidInfoTemp.timestamp = micros() + duration;
    outputContoller.push(solenoidInfoTemp);
    digitalWrite(solenoidInfoTemp.pinNumber, HIGH);
}
