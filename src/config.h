/** =================================
 * System Parameters
================================== */
#define baut 9600
#define RPM 550
#define solenoidDelay (RPM/(60*60))*1000
// Battery Configuration
#define batteryCalibration 0
#define batterySensor 10

/** =================================
 * Shooting Mechanism
================================== */
// weapon trigger
#define trigger 16

/** =================================
 * launch drive
================================== */
// pwm pins for launch drive
#define launchPWM_top 11
#define launchPWM_bottom 12

/** =================================
 * Display
================================== */
// i2c pins for display
#define dispSDA 15
#define dispSCL 16

// Selection interface for display
#define selectorSelectUP 17
#define selectorSelectDOWN 18
#define selectorConfirm 8