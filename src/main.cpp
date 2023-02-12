#include <Arduino.h>
#include <config.h>
#include <Display.h>
#include <Motor.h>
#include <Input.h>
#include <Solenoid.h>

/** =================================
 * Thread Delcaration
================================== */
TaskHandle_t  tDisplay;  
TaskHandle_t  tMotorDriver; 
TaskHandle_t  tSolenoid; 
TaskHandle_t  tInput; 
QueueHandle_t queue;

// continuesly calls task for thread
void DisplayManageTask(void * pvParameters) {
  for(;;) {
    DisplayManager(queue);
  }
}

void MotorManageTask(void * pvParameters) {
  for(;;) {
    ManageMotors(queue);
  }
}

void InputTask(void * pvParameters) {
  for(;;) {
    ManageInput(queue);
  }
}

void SolenoidTask(void * pvParameters) {
  for(;;) {
    ManageSolenoid(queue);
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

  char txBuffer[50];
  queue = xQueueCreate(5, sizeof(txBuffer)); 
  if (queue == 0)
  {
    printf("Failed to create queue= %p\n", queue);
  }

  // task creation
  xTaskCreate(DisplayManageTask, "DisplayManager", 1000, NULL, 5, &tDisplay);
  delay(100);
  xTaskCreate(MotorManageTask, "MotorManager", 1000, NULL, 5, &tMotorDriver);
  delay(100);
  xTaskCreate(InputTask, "InputManager", 1000, NULL, 5, &tInput);
  delay(100);
  xTaskCreate(SolenoidTask, "SolenoidManager", 1000, NULL, 5, &tSolenoid);
}

void loop() {
  // put your main code here, to run repeatedly:
}