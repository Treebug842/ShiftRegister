#include <ShiftRegister74HC595.h>

ShiftRegister74HC595 reg(8, 9, 10);

void setup() { }

void loop() {
  for (int x = 1; x < 9; x++) {
    reg.set(x, HIGH);
    delay(100);
  }
  for (int x = 8; x > 0; x--) {
    reg.set(x, LOW);
    delay(100);
  }
}
