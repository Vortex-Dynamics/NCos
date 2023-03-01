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
char txBuffer[50];

// continuesly calls task for thread
void DisplayManageTask(void * pvParameters) {
  for(;;) {
    // DisplayManager(queue);
  }
}

void MotorManageTask(void * pvParameters) {
  for(;;) {
    if(getMotorState()) {
        // tut das was
    } else {
        // tu was anderes
    }
  }
}

void InputTask(void * pvParameters) {
  for(;;) {
    if (IsButtonPressed(trigger)) {
        //motorSendToQueue = false;
        if(/* motorSendToQueue && */ analogRead(launchPWM_bottom) == 0 && analogRead(launchPWM_top) == 0) {
            xQueueSend(queue, "motorStart", 0);
            //motorSendToQueue = true;
            startMotors();
        }
    }

    if (!IsButtonPressed(trigger)){
        if(analogRead(launchPWM_bottom) > 0 && analogRead(launchPWM_top) > 0) {
            xQueueSend(iQueue, "motorStop", 0);
            stopMotors();
        }
    }
  }
}

void SolenoidTask(void * pvParameters) {
  for(;;) {
    // ManageSolenoid(queue);
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