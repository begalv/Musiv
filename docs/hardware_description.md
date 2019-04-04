# Hardware Description

## List of Components:

- **Arduino Uno:** 
The PIC microcontroller was used to control, through code, the components used in the design. The Arduino sends electrical signals to drive different circuit's parts, like the LED strip and the MSGEQ7 IC, based on the code stored in its memory. 

- **5V 20A Power Supply:** 
The WS2812B LED strip requires about 3A per meter, resulting in the 15A required for this design, leaving the remaining current to feed other components used. All of the components are 5V, except for the adafruit microphone, that is 3V and gets its voltage through arduino 3.3V pin.  

- **MSGEQ7 Integrated Circuit:**
The seven band graphic equalizer IC is a CMOS chip that divides the audio spectrum into seven bands, 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz and 16kHz. The seven frequencies are peak detected and multiplexed to the output to provide a DC representation of the amplitude of each band. The DC peak output for measurement is selected using the reset and strobe pins, permitting multiplexor readout with only two pins. Reset high resets the multiplexor. Reset low enables the strobe pin. After the first strobe leading edge, 63Hz output is on OUT. Each additional strobe leading edge advances the multiplexor one channel (63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, 16kHz etc.) and this will repeat indefinitely.

![Alt](https://github.com/begalv/Musiv/blob/master/docs/images/msgeq7.jpg)

- **MAX4466 Adafruit Electret Microphone Amplifier:**
This board comes with a 20-20KHz electret microphone soldered on and an op-amp Maxim MAX4466 for the amplification. It has excellent power supply noise rejection and adjustable gain, that can be set through a small trimmer pot on the back of the board. For the best performance use the "quietest" supply available (on an Arduino, this would be the 3.3V supply). The audio waveform will come out of the OUT pin, that have a DC bias of VCC/2 so when its perfectly quiet, the voltage will be a steady VCC/2 volts (DC coupled).

![Alt](https://github.com/begalv/Musiv/blob/master/docs/images/mic.jpg)
