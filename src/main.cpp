#include <Arduino.h>
#include <config.h>
#include <Display.h>
#include <Motor.h>

/** =================================
 * Thread Delcaration
================================== */
TaskHandle_t  tDisplay;  
TaskHandle_t  tMotorDriver; 
TaskHandle_t  tSolenoid; 
TaskHandle_t  tInput; 

// continuesly calls task for thread
void DisplayManageTask(void * pvParameters) {
  for(;;) {
    DisplayManager();
  }
}

void MotorManageTask(void * pvParameters) {
  for(;;) {
    ManageMotors();
  }
}

void InputTask(void * pvParameters) {
  for(;;) {
    //ManageMotors();
  }
}

void SolenoidTast(void * pvParameters) {
  for(;;) {
    //ManageMotors();
  }
}

void setup() {
  Serial.begin(baut);  

  // input definitions
  pinMode(trigger, INPUT);
  pinMode(launchPWM_top, OUTPUT);
  pinMode(launchPWM_bottom, OUTPUT);
  pinMode(selectorSelectUP, INPUT);
  pinMode(selectorSelectDOWN, INPUT);
  pinMode(selectorConfirm, INPUT);

  // task creation
  xTaskCreate(DisplayManageTask, "DisplayManager", 1000, NULL, 5, &tDisplay);
  delay(100);
  xTaskCreate(MotorManageTask, "MotorManager", 1000, NULL, 5, &tMotorDriver);
  delay(100);
  xTaskCreate(NULL, "InputManager", 1000, NULL, 5, &tInput);
  delay(100);
  xTaskCreate(NULL, "SolenoidManager", 1000, NULL, 5, &tSolenoid);
}

void loop() {
  // put your main code here, to run repeatedly:
}