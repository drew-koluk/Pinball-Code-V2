#include <ArduinoSTL.h>
#include <vector>
#include "PinballClasses.h"
using namespace std;



vector<int> DropTarget1Pins = {2, 3, 4};

OutputController outControl;

void setup() {
    Serial.begin(9600);
    
    while (!Serial) {}

   

}

void loop() {
   BallTrough ballTrough(5);
   DropTarget testClass(DropTarget1Pins);
  int i = 0;
    for (const auto& coil : testClass.getCoils()) {
        i++;
       coil.fire(outControl,1000000*i);
       Serial.print("Coil #: ");
       Serial.print(i);
       Serial.println("is firing");
    };
    ballTrough.kickBall(outControl);
    while (true){
    outControl.update();  
   
    };
    
  
   
}
