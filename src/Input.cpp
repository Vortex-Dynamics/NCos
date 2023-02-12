#include <Arduino.h>

bool IsButtonPressed(int pin) {
    return (digitalRead(pin) == HIGH);
}