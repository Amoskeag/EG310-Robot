// Pro WHeel
// EG-310, SNHU
#define LOW 0
#define HIGH 1

#include <Arduino.h>
#include "mecanum.h"


Mecanum::Mecanum(int _EncoderPinA, int _EncoderPinB, int _DirPin, int _pwmPin, bool _isInverted = false)
{
    // Make all these init values members of this class
    EncoderPinA = _EncoderPinA;
    EncoderPinB = _EncoderPinB;
    dirPin = _DirPin;
    pwmPin = _pwmPin;
    isInverted = _isInverted;

    // Pinmodes, exercise to the reader ;)
};

void Mecanum::setSpeed(signed int speed)
{
    /* A method to set the speed of
        * this particular mecanum module.
        * Speed is an int from -255 to 255
        */

    int _dir = LOW;

    if (isInverted && !(speed > 0))
    {
        _dir = HIGH;
    }

    // TODO: Clean this up, exercise to the reader ;P
    digitalWrite(dirPin, _dir);

    // Write the PWM value to the pwm pin
    analogWrite(pwmPin, speed);
};

void Mecanum::updateEncoder(){

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

// TODO: Get current speed here!