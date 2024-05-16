#include "SolenoidController.h"
#include "Arduino.h"


void OutputController::remove(int index) {
    if (index >= 0 && index < _outputArray.size()) {
       _outputArray.erase(_outputArray.begin() + index);
    }
}

void OutputController::push(const solenoidInfo& sInfo) {
    _outputArray.push_back(sInfo);
}

void OutputController::update() {
    for (int i = 0; i < _outputArray.size(); i++) {
        if (_outputArray[i].timestamp < micros()) {
            digitalWrite(_outputArray[i].pinNumber, LOW);
            remove(i);
        }
    }
}
