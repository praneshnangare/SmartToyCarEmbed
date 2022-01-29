#ifndef SETUP_H
#define SETUP_H
#include <Arduino.h>
#include <Servo.h>

void drive(uint8_t dir , uint8_t pwmValue);
void steer(uint8_t angle);
void resetPos();
void inwardTrailLED(uint8_t count);
void setAllPins();
void outwardTrailLED(uint8_t count);
void trailLED(uint8_t count);
void leftToRightLED(uint8_t count);
void rightToLeftLED(uint8_t count);
void slidingLED();
void stopAllLED();
void lightUpAllLED();
void flashAllLED();

/*--------LED's configuration START--------*/
//Front Left
#define Lfll A6
#define Lflm 11
#define Lflr 9

//Front Right
#define Lfrl A4
#define Lfrm A2
#define Lfrr A0

#define Lbml 13
#define Lbmr 7
/*--------LED's configuration END--------*/

/*--------Driving Motor Configuration----*/
#define Din1 A4
#define Din2 A5
#define Dpwm 5

/*--------Steering Servo Configuration----*/
#define Ssig A1
extern Servo steerServo;

/*-------IR Sensor Configuration---------*/
#define If 12
#define Il 10
#define Ir 8
#define Ib 6
#define Id 4

/*-------PIR Confiuration----------------*/ 
#define pir A3



/*-------Directions --------------------*/
#define FRONT 1
#define BACK 0
#define CURRENT 2
#define STOP 0

/*------Steering Directions------------*/
#define CENTER 117
#define LEFT 180
#define RIGHT 90



#endif
