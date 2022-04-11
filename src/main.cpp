// EG-310, SNHU
// Joe, Arthur

// Config/Build
//#include "version.h"

// Custom objects
#include <Arduino.h>
// #include "mecanum.h"
#include "operator.h"
#include "Servo.h"

#define PWM_FL 3
#define PWM_FR 4
#define PWM_BL 5
#define PWM_BR 6

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

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop()
{
  pit = STBY - humanOperator.getPitch();
  rol = STBY - humanOperator.getRoll();
  yaw = STBY - humanOperator.getYaw();

  front_left_mecanum.writeMicroseconds(STBY + rol + pit - yaw);
  front_right_mecanum.writeMicroseconds(STBY + -rol + pit - yaw);
  back_left_mecanum.writeMicroseconds(STBY + rol + pit + yaw);
  back_right_mecanum.writeMicroseconds(STBY + -rol + pit + yaw);
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