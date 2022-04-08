// EG-310, SNHU
// Joe, Arthur

// Config/Build
//#include "version.h"

// Custom objects
#include <Arduino.h>
#include "mecanum.h"
#include "operator.h"

#define PWM_FL 9
#define PWM_FR 10
#define PWM_BL 11
#define PWM_BR 12

#define fL_Encoder 2
#define fR_Encoder 3
#define bL_Encoder 20
#define bR_Encoder 21

bool previous_state_A = LOW;

Mecanum front_left_mecanum(4, fL_Encoder, 8, PWM_FL, false);
Mecanum front_right_mecanum(5, fR_Encoder, 13, PWM_FR, true);
Mecanum back_left_mecanum(6, bL_Encoder, 14, PWM_BL, false);
Mecanum back_right_mecanum(7, bR_Encoder, 15, PWM_BR, true);
// More modules

const Operator humanOperator = Operator(1, 2, 3);

// Joe wrote this, remove it later
void fl_encoder_callback()
{
  front_left_mecanum.updateEncoder();
}

void fr_encoder_callback()
{
  front_right_mecanum.updateEncoder();
}

void bl_encoder_callback()
{
  back_left_mecanum.updateEncoder();
}

void br_encoder_callback()
{
  back_right_mecanum.updateEncoder();
}

void setup()
{
  // Setup Serial
  Serial.begin(115200);
  delay(200);

  // Print MOTD
  Serial.println(MOTD);

  // Set Interupt pins, fix code structure later.
  attachInterrupt(digitalPinToInterrupt(fL_Encoder), fl_encoder_callback, RISING);
  attachInterrupt(digitalPinToInterrupt(fR_Encoder), fr_encoder_callback, RISING);
  attachInterrupt(digitalPinToInterrupt(bL_Encoder), bl_encoder_callback, RISING);
  attachInterrupt(digitalPinToInterrupt(bR_Encoder), br_encoder_callback, RISING);
}

void loop()
{
  front_left_mecanum.setSpeed(255);
  front_right_mecanum.setSpeed(255);
  back_left_mecanum.setSpeed(255);
  back_right_mecanum.setSpeed(255);
  delay(1000);
  front_left_mecanum.setSpeed(0);
  front_right_mecanum.setSpeed(0);
  back_left_mecanum.setSpeed(0);
  back_right_mecanum.setSpeed(0);
  delay(1000);
  front_left_mecanum.setSpeed(-255);
  front_right_mecanum.setSpeed(-255);
  back_left_mecanum.setSpeed(-255);
  back_right_mecanum.setSpeed(-255);
  delay(1000);
  front_left_mecanum.setSpeed(0);
  front_right_mecanum.setSpeed(0);
  back_left_mecanum.setSpeed(0);
  back_right_mecanum.setSpeed(0);
  delay(1000);
  front_left_mecanum.setSpeed(0);
  front_right_mecanum.setSpeed(255);
  back_left_mecanum.setSpeed(255);
  back_right_mecanum.setSpeed(0);
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