# Hardware Description

## List of Components:

- **Arduino Uno:** 
The PIC microcontroller was used to control, through code, the components used in the design. The Arduino sends electrical signals to drive different circuit's parts, like the LED strip and the MSGEQ7 IC, based on the code stored in its memory. 

- **5V 20A Power Supply:** 
The WS2812B LED strip requires about 3A per meter, resulting in the 15A required for this design, leaving the remaining current to feed other components used. All of the components are 5V, except for the adafruit microphone, that is 3V and gets its voltage through arduino 3.3V pin.  

- **MSGEQ7 Integrated Circuit:**
The seven band graphic equalizer IC is a CMOS chip that divides the audio spectrum into seven bands, 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz and 16kHz. The seven frequencies are peak detected and multiplexed to the output to provide a DC representation of the amplitude of each band. The DC peak output for measurement is selected using the reset and strobe pins, permitting multiplexor readout with only two pins. Reset high resets the multiplexor. Reset low enables the strobe pin. After the first strobe leading edge, 63Hz output is on OUT. Each additional strobe leading edge advances the multiplexor one channel (63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, 16kHz etc.) and this will repeat indefinitely.

![Alt](https://github.com/begalv/Musiv/blob/master/docs/images/msgeq7.jpg)
