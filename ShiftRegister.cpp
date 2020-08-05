/*
ShiftRegister.h - A library for using 74HC595
and 74HC165 Shift Registers as normal pins.
Created by Treebug842, (DATE) 
*/

#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int dataPin, int latchPin, int clockPin) {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;
}

int ShiftRegister::_getSlot(int pin) {
  int short slot;
  if ((pin >= 1) && (pin <= 8)) { slot = 0; }
  else if ((pin >= 9) && (pin <= 16)) { slot = 1; }
  else if ((pin >= 17) && (pin <= 24)) { slot = 2; }
  else if ((pin >= 25) && (pin <= 32)) { slot = 3; }
  else if ((pin >= 33) && (pin <= 40)) { slot = 4; }
  else if ((pin >= 41) && (pin <= 48)) { slot = 5; }
  else if ((pin >= 49) && (pin <= 56)) { slot = 6; }
  else if ((pin >= 57) && (pin <= 64)) { slot = 7; }
  return (slot);
}

void ShiftRegister::_update() {
  for (int i = 0; i < NumOfRegisters; i++) {
    shiftOut(_dataPin, _clockPin, MSBFIRST, 0);
    delayMicroseconds(10);
  }
  for (int x = NumOfRegisters; x > -1; x--) {
    shiftOut(_dataPin, _clockPin, MSBFIRST, _actives[x]);
    delayMicroseconds(10);
  }
  digitalWrite(_latchPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(_latchPin, LOW);
}

void ShiftRegister::set(int pin, char state) {
  int short slot;
  slot = _getSlot(pin);
  double tmpShift = 0;
  tmpShift = pow(2, int((pin - (8 * slot)) - 1 ));
  tmpShift = tmpShift + 0.5;
  _shifts = (int) tmpShift;

  if (state == HIGH) {
    _actives[slot] += _shifts;
  }
  else if (state == LOW) {
    _actives[slot] -= _shifts;
  }
  _update();
}


void ShiftRegister::setAll(char state) {
  if (state == HIGH) {
    for (int i = 0; i < NumOfRegisters; i++) {
      _actives[i] = 255;
    }
    _update();
  }
  else if (state == LOW) {
    for (int i = 0; i < NumOfRegisters; i++) {
      _actives[i] = 0;
    }
    _update();
  }
}

void ShiftRegister::setNumOfRegisters(int num_of_registers) {
  NumOfRegisters = num_of_registers;
}

void ShiftRegister::setRegisterType(char type) {
  RegisterType = type;
}
  
