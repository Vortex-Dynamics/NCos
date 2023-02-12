#include <Arduino.h>

QueueHandle_t mQueue;
bool isRunning;

void ManageMotors(QueueHandle_t queue){
    mQueue = queue;

    if(isRunning) {
        // tut das was
    } else {
        // tu was anderes
    }
}
void startMotors(){
    isRunning = true;
}
void stopMotors(){
    isRunning = false;
}