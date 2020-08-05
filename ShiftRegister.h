/*
ShiftRegister.h - A library for using 74HC595
and 74HC165 Shift Registers as normal pins.
Created by Treebug842, (DATE) 
*/

#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister {
  public:
    ShiftRegister(const int dataPin, const int latchPin, const int clockPin);
    void set(int pin, char state);
    void setAll(char state);
    int get();
    int getAll();
    void setRegisterType(char type);
    void setNumOfRegisters(int num_of_registers);
    
    char RegisterType = "SIPO";
    unsigned int NumOfRegisters = 1;

  private:
    void _update();
    unsigned short int _num_of_registers;
    unsigned int _dataPin;
    unsigned int _latchPin;
    unsigned int _clockPin;
    unsigned long long int _actives[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long int _shifts;
    int _getSlot(int pin);
};

#endif
