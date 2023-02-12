#include <Arduino.h>

// Start an Instance of the Input Manager
void ManageInput(QueueHandle_t queue);

// returns if the selected pin is true or false
bool IsButtonPressed(int pin);