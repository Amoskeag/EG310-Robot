// EG-310, SNHU
// Joe, Arthur

// Config/Build
//#include "version.h"

// Custom objects
#include <Arduino.h>
#include "mecanum.h"

#define PWM_FL 9
#define PWM_FR 10
#define PWM_BL 11
#define PWM_BR 12

#define fL_Encoder 2
#define fR_Encoder 3
#define bL_Encoder 20
#define bR_Encoder 21

bool previous_state_A = LOW;

Mecanum front_left_mecanum(4, fL_Encoder, 8, PWM_FL);
Mecanum front_right_mecanum(5, fR_Encoder, 13, PWM_FR, true);
Mecanum back_left_mecanum(6, bL_Encoder, 14, PWM_BL);
Mecanum back_right_mecanum(7, bR_Encoder, 15, PWM_BR, true);
// More modules

void setup()
{
  // Init serial
  Serial.begin(115200);

  // Print out some information about the software we're running.
  Serial.println();
  Serial.print("Starting robot software. Using version ");
  // Serial.println(VERSION);
  Serial.print("This software compiled on ");
  // Serial.println(COMPILED_ON);
  Serial.println();

  // Set Interupt pins, fix code structure later.
  attachInterrupt(digitalPinToInterrupt(fL_Encoder), checkEncoder, RISING);
  attachInterrupt(digitalPinToInterrupt(fR_Encoder), checkEncoder, RISING);
  attachInterrupt(digitalPinToInterrupt(bL_Encoder), checkEncoder, RISING);
  attachInterrupt(digitalPinToInterrupt(bR_Encoder), checkEncoder, RISING);

  delay(500);
}

// void checkEncoder()
// {

//   //Direction of wheel
//   int _currentStateA = digitalRead(EncoderPinA);

//   //Look for movement of wheel
//   if( (_currentStateA == LOW) && (_currentStateA == HIGH)){

//     if(digitalRead(EncoderPinB) == HIGH){
//         Serial.println("Right");
//     }
//     else
//     {
//         Serial.println("Left");
//     }
//   }

//   previousStateA = _currentStateA;		//Store

// }

void loop()
{
  front_left_mecanum.setSpeed(255);
  delay(1000);
  front_left_mecanum.setSpeed(0);
  delay(1000);
  front_left_mecanum.setSpeed(-255);
  delay(1000);
  front_left_mecanum.setSpeed(0);
  delay(1000);
}

/*void updateEncoder(int EncoderPinA, int EncoderPinB, bool previousStateA ){

//Direction of wheel
int _currentStateA = digitalRead(EncoderPinA);

//Look for movement of wheel
if( (_currentStateA == LOW) && (_currentStateA == HIGH)){

    if(digitalRead(EncoderPinB) == HIGH){
        Serial.println("Right");
    }
    else
    {
        Serial.println("Left");
    }
}

previousStateA = _currentStateA;		//Store

};
*/