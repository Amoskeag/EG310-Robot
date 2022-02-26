// EG-310, SNHU
// Joe, Arthur

// Config/Build
#include "version.h"

// Custom objects
#include "modules/mecanum_module.cpp"

Mecanum front_left_mecanum(1, 2, 3, 4);
Mecanum front_right_mecanum(5, 6, 7, 8, true);
// More modules, exercise to the reader ;)

void setup()
{
  // Init serial
  Serial.begin(115200);

  // Print out some information about the software we're running.
  Serial.println();
  Serial.print("Starting robot software. Using version ");
  Serial.println(VERSION);
  Serial.print("This software compiled on ");
  Serial.println(COMPILED_ON);
  Serial.println();
  delay(500); // This is ok to use here
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
