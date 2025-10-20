using namespace vex;

extern brain Brain;

extern controller Controller;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

extern motor leftFront;
extern motor leftMiddle;
extern motor leftBack;
extern motor rightFront;
extern motor rightMiddle;
extern motor rightBack;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

extern motor conveyor;
extern motor scorer;

extern digital_out matchLoader;
extern digital_out trapdoor;
extern digital_out park;

extern bool matchLoaderState;
extern bool trapdoorState;
extern bool parkState;

void  vexcodeInit( void );

void conveyorControl();
void scorerControl();

void matchLoaderControl();
void trapdoorControl();
void parkControl();