/** =================================
 * System Parameters
================================== */
#define baut 9600
#define RPM 550
#define solenoidDelay (RPM/(60*60))*1000

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
#define dispSDA 21
#define dispSCL 22

// Selection interface for display
#define selectorSelectA 17
#define selectroSelectr 18
#define selectorConfirm 8