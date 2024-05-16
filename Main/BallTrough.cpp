#include "BallTrough.h"


BallTrough::BallTrough(int pinNum): _coil(pinNum) {}

void BallTrough::kickBall(OutputController& outputContoller){;
    _coil.fire(outputContoller); 
};


