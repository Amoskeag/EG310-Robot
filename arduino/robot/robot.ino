// EG-310, SNHU
// Joe, Arthur

// Config/Build
#include "version.h"


void setup()
{
  // Init serial
  Serial.begin(115200);

  // Print out some information about the software we're running.
  Serial.println(); Serial.print("Starting robot software. Using version "); Serial.println(VERSION);
  Serial.print("This software compiled on "); Serial.println(COMPILED_ON); Serial.println();
  delay(500); // This is ok to use here
}

void loop()
{
  delay(100); //TODO: Write code here
}
