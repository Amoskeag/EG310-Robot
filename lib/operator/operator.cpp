/* EG-110
 * SNHU, CETA
 */

// Headers
#include "operator.h"
#include "Arduino.h"

// Memory
int _ret;

Operator::Operator(int _pitchPin, int _rollPin, int _yawPin, int _recvMin, int _recvMax)
{
    /* Constructs an operator
     */

    // Pins
    pitchPin = _pitchPin;
    pinMode(pitchPin, INPUT);
    rollPin = _rollPin;
    pinMode(rollPin, INPUT);
    yawPin = _yawPin;
    pinMode(yawPin, INPUT);

    // PWM values
    recvMin = _recvMin;
    recvMax = _recvMax;
};

int Operator::getPitch() const
{
    _ret = pulseIn(pitchPin, HIGH);

    // Map ret between -128 and 128
    _ret = map(_ret, recvMin, recvMax, -128, 128);

    return _ret;
};

int Operator::getRoll() const
{
    _ret = pulseIn(rollPin, HIGH);

    // Map ret between -128 and 128
    _ret = map(_ret, recvMin, recvMax, -128, 128);

    return _ret;
};
int Operator::getYaw() const
{
    _ret = pulseIn(yawPin, HIGH);

    // Map ret between -128 and 128
    _ret = map(_ret, recvMin, recvMax, -128, 128);

    return _ret;
};
