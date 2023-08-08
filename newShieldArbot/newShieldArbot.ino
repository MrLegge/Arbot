/*
  shieldBase.h class library to provide bsics of the robotbase with the new shield
  
  Author: Robert Newell + chatGPT  27/7/23
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/

#include "ShieldBase.h"

#define trigPin 8
#define echoPin 7

int carDistance;
ShieldBase *myBase;

void setup()
{
  pinMode(BUZZER, OUTPUT);
  myBase = new ShieldBase(); 
 
}





void loop(){  
  carDistance = ultraSonicDistance(trigPin,echoPin);  // first the distance is queried from the ultrasonic
  if (carDistance > 0){                               // logical decision based on ultrasonic return larger than zero
      if(carDistance < 30){                          
        myBase->driveForward(0,0);                            // stop!
        delay(500);
      }else{                                          //logical reaction based on ultrasonic return larger than 30 less than 3m
        myBase->driveForward(200,200);  
        delay(500);
      }
  }else {                                  //logical reaction based on ultrasonic return less than 0 (distance greater than 3m or reflected not returned?)
      driveForward(250,250);
      delay(500);
      }    
}

/****************ultraSonic distance function*****************************/
  int ultraSonicDistance(int trig, int echo){
    // returns error code or value for use in logic conditions based on offset to object infront
    long duration;
    int distance;
    pinMode(trig, OUTPUT);  // Set the trig pin to output
    pinMode(echo, INPUT);   // Set the echo pin to input
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration/2) / 29;
    if (distance >= 300 ){ // return -1 if bigger than 3m
      return -1;
    }
    else if(distance <= 0){ // returns 0 for error or zero results
      return 0;
    }
    else {
      return distance; // returns a value if test is between 0m and 3m
    }
    delay(100);
  }
/***********************************************************************/
