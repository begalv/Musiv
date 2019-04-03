# Hardware Description

## List of Components:

- **Arduino Uno:** 
The PIC microcontroller was used to control, through code, the components used in the design. The Arduino sends electrical signals to drive different circuit's parts, like the LED strip and the MSGEQ7 IC, based on the code stored in its memory. 

- **5V 20A Power Supply:** 
The WS2812B LED strip requires about 3A per meter, resulting in the 15A required for this design, leaving the remaining current to feed the other components used. All of the components used on the project are 5V, except for the adafruit microphone, that is 3V and gets its voltage through arduino 3.3V pin.  

- **MSGEQ7 Integrated Circuit:**
