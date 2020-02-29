# Musiv

This project consists on a simple LED strip that reacts to music. The circuit uses two adafruit's electret microphone amplifiers (left and right) with adjustable gain to capture audio waves in the air. By code, it filters the noises so that only the music waves (loudest waves in the room) are taken into account. Then the MSGEQ7 integrated circuit divides the volumes peaks of the filtered frequencies into a seven values array, that is updated everytime the function is called on arduino's iteration.

With these values in the array, the code can create a frame iteration that updates the average bass, snare and hat volumes in each frame, so depending in the new loudest volume peak, divided per its band average, a function returns a three values array (R, G, B), that are the color values passed to the LED strip. 

So, the circuit outputs different colors to the LEDs strip depending on the current loudest frequency in the air and its average, meaning that if the basses in the music are loud in some part, the LEDs will blink more cold colors than if the hats were. Also, if the loudest frequencies don't surpass its averages, the LEDs will not blink so it can stay synced with the music's beat. 

Project's video: https://drive.google.com/open?id=1zkOYvlQEQ5gqLZ5uRXyxAB95kZNgsWEG

**obs: This project was developed by a first-semester student of computer science**
_______________________________________

![Alt](https://github.com/begalv/Musiv/blob/master/docs/images/IMG_20190409_215012.jpg)
![Alt](https://github.com/begalv/Musiv/blob/master/docs/images/left.jpg)
