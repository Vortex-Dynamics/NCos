#include <Arduino.h>
#include <config.h>

void FireSolenoid(int pin) {
    digitalWrite(pin, HIGH);
    delay((uint32_t)solenoidDelay);
    digitalWrite(pin, LOW);
}