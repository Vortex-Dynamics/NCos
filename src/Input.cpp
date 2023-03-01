#include <Arduino.h>
#include <config.h>
#include <Input.h>
#include <Motor.h>

bool IsButtonPressed(int pin) {
    return (digitalRead(pin) == HIGH);
}