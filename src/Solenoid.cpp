#include <Arduino.h>
#include <config.h>

QueueHandle_t sQueue;

void ManageSolenoid(QueueHandle_t queue) {
    sQueue = queue;
}

void FireSolenoid(int pin) {
    digitalWrite(pin, HIGH);
    delay((uint32_t)solenoidDelay);
    digitalWrite(pin, LOW);
}