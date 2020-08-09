#include <ShiftRegister74HC595.h>

ShiftRegister74HC595 reg(8, 9, 10);   // Creates reg object (datapin, latchpin, clockpin);

void setup() { 
reg.setNumOfRegisters(2);             // Sets number of registers being used to 2, default is 1
}

void loop() {
  reg.setAll(HIGH);       // Sets all of the pins (2 registers) to HIGH
  delay(1000);            // One second delay
  reg.setAll(LOW);        // Sets all of the pins (2 registers) to LOW
  delay(1000);            // One second delay
} 
