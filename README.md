# DDRB 
This is a Digital Decade Resistor Box. This is the same as a Decade Resistor box, but uses an Arduino with LCD and Keypad to set the value. This will also allow the user to check the box and insure it's still within spec.

List of Features
  - LCD Readout of Resistance
  - Keypad to set resistance
  - Sub Ohm of .01 - .99 
  - Ohm 2^30 of Resistance ≈ 1,073,741,824 Ohms
  - Modular Cards, Easily replacable for Increased precistion (with Increase of Cst to the board)
  - 2 Expanstion Slots, Each with three Pins to the MCU (Future Expanstion) Signal Does Pass through these.
    - Possible uses
      - reading resistance from start to finish (will require slight rework of Buss Board)
      - Altering Resistance to give "True" value
      - Pulsed Output such as Sig Gen using Resistance values.
  - uses Binary Resistance values to get final resuslts:
    - 1 ohm + 2 ohm + 8 ohm = 11 ohms of resistance ECT. 
      - Should reduce cost
