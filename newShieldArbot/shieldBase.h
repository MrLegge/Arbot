/*
  shieldBase.h class library to provide bsics of the robotbase with the new shield
  
  Author: Robert Newell + chatGPT  27/7/23
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/

#define trigPin 8
#define echoPin 7
//  Motor Right
int const rightMotorSpeedPin = 10;
int const rightMotorDirectionPin = 12;
//  Motor Left
int const leftMotorSpeedPin = 11;
int const leftMotorDirectionPin = 13;

int carDistance;

int const BUZZER = 4;

int const MIN_SPEED = 30;   // Set to minimum PWM value that will make motors turn
int const ACCEL_DELAY = 50; // delay between steps when ramping motor speed up or down.
void Motor(char mot, char dir, int speed)
{
 
}


//Function to drive the car forward with custom left and right motor speeds.
void driveForward(int leftMotorSpeed, int rightMotorSpeed)
{
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
void driveBackward(int leftMotorSpeed, int rightMotorSpeed)
{
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
void rotateRight(int rotateSpeed)
{
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
void rotateLeft(int turnSpeed)
{
  // Ensure the turn speed is within the valid range (0 to 255).
  turnSpeed = constrain(turnSpeed, 0, 255);

  // Set the directions for rotation.
  digitalWrite(leftMotorDirectionPin, LOW);
  digitalWrite(rightMotorDirectionPin, HIGH);

  // Set the motor speeds for rotation.
  analogWrite(leftMotorSpeedPin, turnSpeed);
  analogWrite(rightMotorSpeedPin, turnSpeed);
}
