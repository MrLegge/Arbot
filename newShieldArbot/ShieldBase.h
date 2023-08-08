/*
  shieldBase.h class library to provide basics of the robotbase with the new shield
  
  Author: Robert Newell + chatGPT  27/7/23
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/
#ifndef CARBASE_H
#define CARBASE_H

class ShieldBase{
  public:
    const int BUZZER = 4;
    const int MIN_SPEED = 30;   // Set to minimum PWM value that will make motors turn
    const int ACCEL_DELAY = 50; // delay between steps when ramping motor speed up or down.

    //  Motor Right
    int rightMotorSpeedPin, rightMotorDirectionPin;
    //  Motor Left
    int leftMotorSpeedPin, leftMotorDirectionPin;

    ShieldBase();

    void driveForward(int, int);
    void driveBackward(int, int);
    void rotateRight(int);
    void rotateLeft(int);

  private:

};

#endif 
