using namespace vex;

extern brain Brain;

extern controller Controller;

// Drive motors

extern motor leftFront;
extern motor leftMiddle;
extern motor leftBack;
extern motor rightFront;
extern motor rightMiddle;
extern motor rightBack;

// Devices

extern motor conveyor;
extern motor scorer;

extern digital_out matchLoader;
extern digital_out trapdoor;
extern digital_out park;

extern bool matchLoaderState;
extern bool trapdoorState;
extern bool parkState;

// Formulas

void vexcodeInit( void );

void conveyorControl();
void scorerControl();

void matchLoaderControl();
void trapdoorControl();
void parkControl();