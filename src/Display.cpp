#include <Arduino.h>

int displayIndex = 0;
QueueHandle_t dQueue;

void DisplayManager(QueueHandle_t queue){
    dQueue = queue;
    // TODO write controll + display code
}

void displayMessage(){}

int getDisplayIndex(){
    return displayIndex;
}

void setDisplayIndex(int index){
    displayIndex = index;
}