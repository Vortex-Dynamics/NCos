#include <Arduino.h>

// start a Display Manager Instance
void DisplayManager(QueueHandle_t queue);

// gets the currently active displayIndex
int getDisplayIndex();

// changes the current displayIndex to change currently shown content on the Display
void setDisplayIndex(int index);