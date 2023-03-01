#include <Arduino.h>
bool isRunning;

void startMotors(){
    isRunning = true;
}
void stopMotors(){
    isRunning = false;
}
bool getMotorState(){
    return isRunning;
}