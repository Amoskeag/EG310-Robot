/* EG-110
 * SNHU, CETA
 */

class Operator
{
private:
    int pitchPin;
    int rollPin;
    int yawPin;
    int recvMin;
    int recvMax;

public:
    Operator(int _pitchPin, int _rollPin, int _yawPin, int _recvMin = 1100, int _recvMax = 1800);

    int getPitch() const;
    int getRoll() const;
    int getYaw() const;
};
