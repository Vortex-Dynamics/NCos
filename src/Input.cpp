#include <Arduino.h>
#include <config.h>
#include <Input.h>
#include <Motor.h>

QueueHandle_t iQueue;
//bool motorSendToQueue = false;

void ManageInput(QueueHandle_t queue){
    iQueue = queue;
    if (IsButtonPressed(trigger)) {
        //motorSendToQueue = false;
        if(/* motorSendToQueue && */ analogRead(launchPWM_bottom) == 0 && analogRead(launchPWM_top) == 0) {
            //xQueueSend(iQueue, "motorStart", 0);
            //motorSendToQueue = true;
            startMotors();
        }
    }

    if (!IsButtonPressed(trigger)){
        if(analogRead(launchPWM_bottom) > 0 && analogRead(launchPWM_top) > 0) {
            //xQueueSend(iQueue, "motorStop", 0);
            stopMotors();
        }
    }
}

bool IsButtonPressed(int pin) {
    return (digitalRead(pin) == HIGH);
}