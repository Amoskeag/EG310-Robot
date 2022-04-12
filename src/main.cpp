// EG-310, SNHU
// Joe, Arthur

// Config/Build
//#include "version.h"

// Custom objects
#include <Arduino.h>
// #include "mecanum.h"
#include "operator.h"
#include "Servo.h"

#define PWM_FL 10
#define PWM_FR 11
#define PWM_BL 12
#define PWM_BR 13

#define STBY 1500

bool previous_state_A = LOW;

// Mecanum front_left_mecanum(4, fL_Encoder, 8, PWM_FL, false);
// Mecanum front_right_mecanum(5, fR_Encoder, 13, PWM_FR, true);
// Mecanum back_left_mecanum(6, bL_Encoder, 14, PWM_BL, false);
// Mecanum back_right_mecanum(7, bR_Encoder, 15, PWM_BR, true);
Servo front_left_mecanum;
Servo front_right_mecanum;
Servo back_left_mecanum;
Servo back_right_mecanum;
// More modules

const Operator humanOperator = Operator(51, 50, 52);

int pit;
int rol;
int yaw;

int _fl;
int _fr;
int _bl;
int _br;

void setup()
{
  // Setup Serial
  Serial.begin(115200);
  delay(200);

  // Print MOTD
  Serial.println(MOTD);

  // // Set Interupt pins, fix code structure later.
  // attachInterrupt(digitalPinToInterrupt(fL_Encoder), fl_encoder_callback, RISING);
  front_left_mecanum.attach(PWM_FL);
  // attachInterrupt(digitalPinToInterrupt(fR_Encoder), fr_encoder_callback, RISING);
  front_right_mecanum.attach(PWM_FR);
  // attachInterrupt(digitalPinToInterrupt(bL_Encoder), bl_encoder_callback, RISING);
  back_left_mecanum.attach(PWM_BL);
  // attachInterrupt(digitalPinToInterrupt(bR_Encoder), br_encoder_callback, RISING);
  back_right_mecanum.attach(PWM_BR);
}

void loop()
{
  pit = STBY - humanOperator.getPitch();
  rol = STBY - humanOperator.getRoll();
  yaw = STBY - humanOperator.getYaw();

  // _fl = STBY + rol + pit - yaw;
  // _fr = STBY + -rol + pit - yaw;
  // _bl = STBY + rol + pit + yaw;
  // _br = STBY + -rol + pit + yaw;

  _fl = STBY - pit;
  _fr = STBY + pit;
  _bl = STBY - pit;
  _br = STBY - pit; // Wired wrong

  if (abs(STBY - _fl) > 100)
  {
    front_left_mecanum.writeMicroseconds(_fl);
  }
  else
  {
    front_left_mecanum.writeMicroseconds(STBY);
  }

  if (abs(STBY - _fr) > 100)
  {
    front_right_mecanum.writeMicroseconds(_fr);
  }
  else
  {
    front_right_mecanum.writeMicroseconds(STBY);
  }

  if (abs(STBY - _bl) > 100)
  {
    back_left_mecanum.writeMicroseconds(_bl);
  }
  else
  {
    back_left_mecanum.writeMicroseconds(STBY);
  }

  if (abs(STBY - _br) > 100)
  {
    back_right_mecanum.writeMicroseconds(_br);
  }
  else
  {
    back_right_mecanum.writeMicroseconds(STBY);
  }
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