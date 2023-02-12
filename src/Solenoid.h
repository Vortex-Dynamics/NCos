#include <Arduino.h>

void ManageSolenoid(QueueHandle_t queue);

// sends a fire impuls on a selected solenoid pin
void FireSolenoid(int pin);