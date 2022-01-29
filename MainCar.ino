/*
   -- New project --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.7 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.9.02 or later version;
     - for iOS 1.6.2 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP8266_SOFTSERIAL_POINT
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,4,0,119,0,14,16,0,
  2,1,3,8,22,11,2,26,31,31,
  79,78,0,79,70,70,0,3,132,52,
  9,25,7,2,26,4,48,87,25,7,
  37,2,26,4,176,0,52,38,7,2,
  26,71,56,39,29,40,40,4,2,8,
  135,0,0,0,0,0,0,200,66,0,
  0,160,65,0,0,32,65,0,0,0,
  64,24,80,101,114,99,101,110,116,0,
  135,0,0,0,0,0,0,72,66,94,
  0,0,72,66,0,0,160,66,36,0,
  0,160,66,0,0,190,66,24,0,0,
  190,66,0,0,200,66 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t powerOn; // =1 if switch ON and =0 if OFF 
  uint8_t ledMode; // =0 if select position A, =1 if position B, =2 if position C, ... 
  int8_t throttle; // =-100..100 slider position 
  int8_t steering; // =-100..100 slider position 

    // output variables
  float speedometer;

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



int8_t val = 0;
int8_t var = 0;
int8_t var1 = 0;
uint8_t prevLedMode = 0;
boolean firstTime = true;
#include "setup.h"
unsigned long   t1;
void setup()
{
  RemoteXY_Init ();
  Serial.begin(9600);
  setAllPins();
  resetPos();
  prevLedMode = RemoteXY.ledMode;
}

void loop()
{//steerServo.detach();
  t1 = micros();
  RemoteXY_Handler ();
//  delay(1000);
  Serial.println( micros() - t1);
  //Serial.println("helo");
  //delay(5000);
  if (RemoteXY.powerOn) {
//    Serial.println("on");
//    RemoteXY.leftLed_g = 255;
//    RemoteXY.rightLed_g = 255;
    if(firstTime) trailLED(0);
    driveMain();
//    steerMain();
//    LEDModeSelection();
  }
  else {
//    flashAllLED();
  }
}


void driveMain() {
  val  = RemoteXY.throttle;
  drive((val < 0) ? BACK : FRONT , abs(val)*2.5);
//  Serial.print("val-");
//  Serial.println(val);
  RemoteXY.speedometer = (float) val;
}

void steerMain() {
  var = RemoteXY.steering;
  //Serial.print("steer-");
  //Serial.println(var);
  var1 = map(var , -100 , 100 , LEFT , RIGHT);
  steer(var1);
/*  if(var>0) {
    RemoteXY.leftLed_r = 0;
    RemoteXY.leftLed_g = 0;
    RemoteXY.leftLed_b = 0;
    
    RemoteXY.rightLed_r = 0;
    RemoteXY.rightLed_g = 0;
    RemoteXY.rightLed_b = 255;
  }
  else if(var<0){
    RemoteXY.rightLed_r = 0;
    RemoteXY.rightLed_g = 0;
    RemoteXY.rightLed_b = 0;

    RemoteXY.leftLed_r = 0;
    RemoteXY.leftLed_g = 0;
    RemoteXY.leftLed_b = 255;   
  }
*/
}

void LEDModeSelection() {
  val = RemoteXY.ledMode;
  if (prevLedMode != val) {
    switch (val) {
      case 0: stopAllLED();
        break;
      case 1: trailLED(1);
        break;
      case 2: slidingLED();
        break;
      case 3: lightUpAllLED();
        break;
    }
    prevLedMode = val;
  }
}
