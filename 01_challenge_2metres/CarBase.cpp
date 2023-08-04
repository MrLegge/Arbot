/*
  base class function definitions to get the car working in object oriented programming
  For the 2019 Manditory Tech course
  
  Author: Phil Legge 12/11/18
  email: phil.legge@det.nsw.edu.au
*/

#include "CarBase.h"

  CarBase::CarBase(){
      // signal pins need to be pwm pins on the UNO board (~ near the number)
      rightSignal = 3;  //ENB
      leftSignal = 10;  //ENA
      // these pins don't need to be pwm
      rightIn1 = 5; //IN3
      rightIn2 = 4;  //IN4
      leftIn1 = 9;  //IN1
      leftIn2 = 6;  //IN2
      
      // the small cheap red motor controller available everywhere is the L298N
      _motorRight = new L298N(rightSignal,rightIn1,rightIn2);
      _motorLeft = new L298N(leftSignal,leftIn1,leftIn2);
    }
  void CarBase::driveForward(unsigned short rightWheel, unsigned short leftWheel){
      _motorRight->setSpeed(rightWheel);
      _motorLeft->setSpeed(leftWheel);
      _motorRight->backward();
      _motorLeft->forward();
    }
  void CarBase::driveBackward(unsigned short rightWheel, unsigned short leftWheel){
      _motorRight->setSpeed(rightWheel);
      _motorLeft->setSpeed(leftWheel);
      _motorRight->forward();
      _motorLeft->backward();
    
    }
  void CarBase::rotateRight(unsigned short turnSpeed){
      _motorRight->setSpeed(turnSpeed);
      _motorLeft->setSpeed(turnSpeed);
      _motorRight->backward();
      _motorLeft->backward();
    
    }
  void CarBase::rotateLeft(unsigned short turnSpeed){
      _motorRight->setSpeed(turnSpeed);
      _motorLeft->setSpeed(turnSpeed);
      _motorRight->forward();
      _motorLeft->forward();
    
    }
