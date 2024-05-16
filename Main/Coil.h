#ifndef COIL_H
#define COIL_H

#include "SolenoidController.h"

class Coil {
private:
    int _pinNumber;
public:
    Coil(int pinNum);

    int getPinNumber() const;
    void fire(OutputController& outputContoller, unsigned long duration = 1000000) ;
};

#endif /* COIL_H */
