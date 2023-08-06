#include "L298Pshield.h"



void setup()
{
  pinMode(rightMotorSpeedPin, OUTPUT);        // set all the motor control pins to outputs
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightMotorDirectionPin, OUTPUT);
  pinMode(leftMotorDirectionPin, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);                    // Set the echo pin to input
 
 
}





void loop(){  
  carDistance = ultraSonicDistance(trigPin,echoPin);  // first the distance is queried from the ultrasonic
  if (carDistance > 0){                               // logical decision based on ultrasonic return larger than zero
      if(carDistance < 30){                          
        driveForward(0,0);                            // stop!
        delay(500);
      }else{                                          //logical reaction based on ultrasonic return larger than 30 less than 3m
               driveForward(200,200);  
        delay(500);
      }
  }else {                                   //logical reaction based on ultrasonic return less than 0 (distance greater than 3m or reflected not returned?)
     
      driveForward(250,250);
      delay(500);
      }    
}
