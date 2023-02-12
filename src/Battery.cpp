#include <Arduino.h>
#include <config.h>

int bat_percentage;
int sensorValue;

float BatteryVoltage(){
    sensorValue = analogRead(batterySensor);
    float voltage= sensorValue * (5.0 / 1023.0);    return voltage;
}

int BatteryVoltageInPercent() {

    bat_percentage = map(BatteryVoltage(), 2.8, 4.2, 0, 100); //2.8V as Battery Cut off Voltage & 4.2V as Maximum Voltage
    
    if (bat_percentage >= 100) {
        bat_percentage = 100;
    } else if (bat_percentage <= 0) {
        bat_percentage = 1;
    }

    return bat_percentage;
}
