
#ifndef BALLTROUGH_H
#define BALLTROUGH_H

#include "coil.h"

class BallTrough{
private:
    Coil _coil;
public: 
    BallTrough(int pinNum);
    void kickBall(OutputController& outputContoller);
};

#endif