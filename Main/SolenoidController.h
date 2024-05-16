#ifndef SOLENOID_CONTROLLER
#define SOLENOID_CONTROLLER

#include <vector>


struct solenoidInfo {
    int pinNumber;
    unsigned long timestamp;
};


class OutputController {
private:
    std::vector<solenoidInfo> _outputArray;

    void remove(int index);
public:
    void push(const solenoidInfo& sInfo);
    void update();
};


#endif