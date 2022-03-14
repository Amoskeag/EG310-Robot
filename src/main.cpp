// EG-310, SNHU
// Joe, Arthur

// Config/Build
//#include "version.h"

// Custom objects
#include <Arduino.h>
#include "mecanum.h"

Mecanum front_left_mecanum(1, 2, 3, 4);
Mecanum front_right_mecanum(5, 6, 7, 8, true);
// Mecanum back_left_mecanum(x, )
//  More modules, exercise to the reader ;)

void setup()
{
  // Setup Serial
  Serial.begin(115200);

  Serial.println("Configured Serial Interfaces.");
  Serial.println("This software expects your terminal to be \x1B[46mVT100 Compatable\x1B[0m.");

  // Print MOTD
  Serial.println(MOTD);
  delay(500);
}

void loop()
{
  front_left_mecanum.setSpeed(255);
  delay(1000); // Dont do dis irl lol
  front_left_mecanum.setSpeed(0);
  delay(1000); // Dont do dis irl lol
  front_left_mecanum.setSpeed(-255);
  delay(1000); // Dont do dis irl lol
  front_left_mecanum.setSpeed(0);
  delay(1000); // Dont do dis irl lol
}
