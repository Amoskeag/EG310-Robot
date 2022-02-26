// Pro WHeel
// EG-310, SNHU

class Mecanum
{
private:
    unsigned int encApin; // A Channel encoder pin
    unsigned int encBpin; // B Channel encoder pin
    unsigned int dirPin;  // Determines the direction of this module.
    unsigned int pwmPin;  // PWM pin to determine speed
    bool isInverted;      // Is this module inverted?
public:
    Mecanum(unsigned int _EncApin, unsigned int _EncBpin, unsigned int _DirPin, unsigned int _pwmPin, bool _isInverted = false)
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
