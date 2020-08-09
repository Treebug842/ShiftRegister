# ShiftRegister
An Arduino Library to use both 74HC595 and 74HC165 chips as regular pins. Pretty simple and I know its been done before, but i wanted to make my own. Its real easy to use and only has a few functions. It will work with up to 8 shift registers daisychained. Here are the key terms in the library:

```
ShiftRegister74HC5959 object(dataPin, latchPin, clockPin);
object.set(pin, STATE);
object.setAll(STATE);
object.setNumOfRegisters(num);
```

