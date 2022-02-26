// Pro WHeel
// EG-310, SNHU

class Mecanum
{
private:
    byte encApin;    // A Channel encoder pin
    byte encBpin;    // B Channel encoder pin
    byte dirPin;     // Determines the direction of this module.
    byte pwmPin;     // PWM pin to determine speed
    bool isInverted; // Is this module inverted?
public:
    Mecanum(byte _EncApin, byte _EncBpin, byte _DirPin, byte _pwmPin, bool _isInverted = false)
    {
        // Make all these init values members of this class
        encApin = _EncApin;
        encBpin = _EncBpin;
        dirPin = _DirPin;
        pwmPin = _pwmPin;
        isInverted = _isInverted;
    };

    void setSpeed(signed int speed)
    {
        /* A method to set the speed of
         * this particular mecanum module.
         * Speed is an int from -255 to 255
         */

        int _dir = LOW;

        if (isInverted and not speed > 0)
        {
            _dir = HIGH;
        }

        // TODO: Clean this up, exercise to the reader ;P
        digitalWrite(dirPin, _dir);

        // Write the PWM value to the pwm pin
        analogWrite(pwmPin, speed);
    };

    // TODO: Get current speed here!
};
