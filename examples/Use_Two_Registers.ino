#include <ShiftRegister74HC595.h>

ShiftRegister74HC595 reg(8, 9, 10);

void setup() { 
reg.setNumOfRegisters(2);  
}

void loop() {
  reg.setAll(HIGH);
  delay(1000);
  reg.setAll(LOW);
  delay(1000);
}
