/*
  shieldBase.cpp class library to provide basics of the robotbase with the new shield
  
  Author: Robert Newell + chatGPT  27/7/23
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/
#include "ShieldBase.h"
#include "Arduino.h"

ShieldBase::ShieldBase(){
  //Motor Right 
  rightMotorSpeedPin = 10;
  rightMotorDirectionPin = 12;
  //  Motor Left
  leftMotorSpeedPin = 11;
  leftMotorDirectionPin = 13;
}

//Function to drive the car forward with custom left and right motor speeds.
void ShieldBase::driveForward(int leftMotorSpeed, int rightMotorSpeed){
  // Ensure the motor speeds are within the valid range (0 to 255).
  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  // Set the directions for forward motion.
  digitalWrite(leftMotorDirectionPin, HIGH);
  digitalWrite(rightMotorDirectionPin, HIGH);

  // Set the motor speeds.
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);
}

//Function to drive the car backward with custom left and right motor speeds.
void ShieldBase::driveBackward(int leftMotorSpeed, int rightMotorSpeed){
  // Ensure the motor speeds are within the valid range (0 to 255).
  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  // Set the directions for backward motion.
  digitalWrite(leftMotorDirectionPin, LOW);
  digitalWrite(rightMotorDirectionPin, LOW);

  // Set the motor speeds.
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);
}

// Function to rotate the car right with left wheel forward and right wheel backward.
void ShieldBase::rotateRight(int rotateSpeed){
  // Ensure the rotation speed is within the valid range (0 to 255).
  rotateSpeed = constrain(rotateSpeed, 0, 255);

  // Set the directions for rotation.
  digitalWrite(leftMotorDirectionPin, HIGH);
  digitalWrite(rightMotorDirectionPin, LOW);

  // Set the motor speeds for rotation.
  analogWrite(leftMotorSpeedPin, rotateSpeed);
  analogWrite(rightMotorSpeedPin, rotateSpeed);
}

// Function to rotate the car left with right wheel forward and left wheel backward.
void ShieldBase::rotateLeft(int turnSpeed){
  // Ensure the turn speed is within the valid range (0 to 255).
  turnSpeed = constrain(turnSpeed, 0, 255);

  // Set the directions for rotation.
  digitalWrite(leftMotorDirectionPin, LOW);
  digitalWrite(rightMotorDirectionPin, HIGH);

  // Set the motor speeds for rotation.
  analogWrite(leftMotorSpeedPin, turnSpeed);
  analogWrite(rightMotorSpeedPin, turnSpeed);
}
