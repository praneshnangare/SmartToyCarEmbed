#include "setup.h"
#include <Servo.h>

int led[8] = {Lfll , Lflm , Lflr , Lfrl , Lfrm , Lfrr , Lbml , Lbmr};
Servo steerServo;

void drive(uint8_t dir , uint8_t pwmValue) {
  analogWrite(Dpwm , pwmValue);
  if (dir) {
  //  Serial.print("front  ");
    //    Serial.println(pwmValue);
//    digitalWrite(Din1 , HIGH);
//    digitalWrite(Din2 , LOW);

        digitalWrite(Din1 , LOW);
    digitalWrite(Din2 , HIGH);


  }
  else {
//        Serial.println("back");
Serial.print("back  ");
        Serial.println(pwmValue);
//    digitalWrite(Din1 , LOW);
//    digitalWrite(Din2 , HIGH);

        digitalWrite(Din1 , HIGH);
    digitalWrite(Din2 , LOW);
  }
}

void steer(uint8_t angle) {
  if (angle < 95) angle = 95;
  else if (angle > 130) angle = 130;
  steerServo.attach(Ssig);
  steerServo.write(angle);
  delay(500);
  steerServo.detach();
}

void resetPos() {
  drive(CURRENT , STOP);
  steer(CENTER);
}

//LED Functions
void inwardTrailLED(uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    digitalWrite(Lflr , HIGH);
    digitalWrite(Lfrl , HIGH);
    delay(200);
    digitalWrite(Lflm , HIGH);
    digitalWrite(Lfrm , HIGH);
    delay(200);
    digitalWrite(Lfll , HIGH);
    digitalWrite(Lfrr , HIGH);
    delay(200);
  }
}

void outwardTrailLED(uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    digitalWrite(Lfll , HIGH);
    digitalWrite(Lfrr , HIGH);
    delay(200);
    digitalWrite(Lflm , HIGH);
    digitalWrite(Lfrm , HIGH);
    delay(200);
    digitalWrite(Lflr , HIGH);
    digitalWrite(Lfrl , HIGH);
    delay(200);
  }
}

void trailLED(uint8_t count) {
  outwardTrailLED(count);
  inwardTrailLED(count);
}

void leftToRightLED(uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    for (uint8_t j = 0; j < 6; j++) {
      digitalWrite(led[j] , HIGH);
      delay(200);
      digitalWrite(led[j] , LOW);
    }
  }
}

void rightToLeftLED(uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    for (uint8_t j = 5; j >= 0; j--) {
      digitalWrite(led[j] , HIGH);
      delay(200);
      digitalWrite(led[j] , LOW);
    }
  }
}

void slidingLED() {
  leftToRightLED(1);
  rightToLeftLED(1);
}

//In this function we have shutdown all the led's
//so we can directly use the port manupulation to do so later
void stopAllLED() {
  digitalWrite(Lflr , LOW);
  digitalWrite(Lfrl , LOW);
  digitalWrite(Lflm , LOW);
  digitalWrite(Lfrm , LOW);
  digitalWrite(Lfll , LOW);
  digitalWrite(Lfrr , LOW);
}

void lightUpAllLED() {
  digitalWrite(Lflr , HIGH);
  digitalWrite(Lfrl , HIGH);
  digitalWrite(Lflm , HIGH);
  digitalWrite(Lfrm , HIGH);
  digitalWrite(Lfll , HIGH);
  digitalWrite(Lfrr , HIGH);
}

void flashAllLED(){
  for (uint8_t i=0;i<6;i++)
    digitalWrite(led[i] , HIGH);
  delay(300);
  for (uint8_t i=0;i<6;i++)
    digitalWrite(led[i] , LOW);
  delay(300);
}
void setAllPins() {
  //LED's
//  pinMode(Lfll , OUTPUT);
//  pinMode(Lflm , OUTPUT);
//  pinMode(Lflr , OUTPUT);
//  pinMode(Lfrl , OUTPUT);
//  pinMode(Lfrm , OUTPUT);
//  pinMode(Lfrr , OUTPUT);
//  pinMode(Lbml , OUTPUT);
//  pinMode(Lbmr , OUTPUT);
//
//  //Driving Motor
//  pinMode(Din1 , OUTPUT);
//  pinMode(Din2 , OUTPUT);
//  pinMode(Dpwm , OUTPUT);
//
//  //IR Pins
//  pinMode(If , INPUT);
//  pinMode(Il , INPUT);
//  pinMode(Ir , INPUT);
//  pinMode(Ir , INPUT);
//  pinMode(Ib , INPUT);

  //Servo Configuration
  //steerServo.attach(Ssig);
  //PIR Pins
//  pinMode(pir , INPUT);

}
