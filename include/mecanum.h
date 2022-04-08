/*
 *   Arthur W. Aznive Jr.
 *   Mecanum.h file
 *   DESCRIPTION: HEader file for Mecanum wheel module.
 *
 */

#include "Servo.h"

class Mecanum
{
private:
    int EncoderPinA; // A Channel encoder pin
    int EncoderPinB; // B Channel encoder pin
    int dirPin;      // Determines the direction of this module.
    int pwmPin;      // PWM pin to determine speed
    bool isInverted; // Is this module inverted?
    int previousStateA;
    Servo moduleServo;

public:
    Mecanum(int _EncApin, int _EncBpin, int _DirPin, int _pwmPin, bool _isInverted = false);

    void begin();

    void setSpeed(signed int speed);

    void setRawSpeed(int speed) const;

    void updateEncoder();

    void getSpeed();
};