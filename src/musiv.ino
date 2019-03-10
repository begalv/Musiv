#include <FastLED.h>

//LED's constants
#define numLeds 300
#define ledsPin 6

//MSGEQ7's constants
#define analogPin A0
#define strobePin 4
#define resetPin 5
#define noise 125
CRGB leds[numLeds];

//average volume's peak for bass, snare and hat
const int frames = 50; 
int frame = 1;
int bass[frames];
int snare[frames];
int hat[frames];


//sets the MSGEQ7's voltage output wave to the first frequency band of the wave (63Hz)
void resetOutputWave() {
  digitalWrite(resetPin, HIGH);
  delay(100/1000000);
  digitalWrite(resetPin, LOW);
}

//gets the volume's peak of each frequency band
int* getBandsVolumes(){
  static int spectrumValue[7];
    for(int i = 0; i < 7; i++){
      digitalWrite(strobePin, LOW);
      delayMicroseconds(30);
      spectrumValue[i] = constrain(analogRead(analogPin), noise, 1023);
      digitalWrite(strobePin, HIGH);
      delayMicroseconds(30);
   }
  return spectrumValue;
}

//gets an array's average
double getArrayAverage(int* arr, int siz){
  double sum = 0;
  double average;
  for (int i = 0; i < siz; i++){
    sum += arr[i];
  }
  average = sum/siz; 
  return average;
}

void setup() {
  FastLED.addLeds<NEOPIXEL, ledsPin>(leds, numLeds);
  
  //The IC MSGEQ7's outputs are the arduino's inputs, and vice versa
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  
  //sets the MSGEQ7's reset input wave to 0V
  digitalWrite(resetPin, LOW);
  //sets the MSGEQ7's voltage output wave to the begin of the wavelenght
  digitalWrite(strobePin, HIGH);

}

//gets an array with RGB values based on bass, snare and hat averages and current peaks
int* getColor(int* spectrumValue){
  static int color[3];
  int newBass = spectrumValue[0] + spectrumValue[1]; 
  int newSnare = spectrumValue[3]; 
  int newHat = spectrumValue[5] + spectrumValue[6];

  double bassAverage = getArrayAverage(bass, frames);
  double snareAverage = getArrayAverage(snare, frames);
  double hatAverage = getArrayAverage(hat, frames);
  
  if(newBass/bassAverage > 1.3){
    color[0] = map(newBass, 100, 1023, 0, 150);
    color[1] = 0;
    color[2] = map(newBass, 100, 1023, 200, 255);
  }  
  else if(newSnare/snareAverage > 1.15){
    color[0] = map(newSnare, 100, 1023, 0, 255);
    color[1] = map(newSnare, 100, 1023, 200, 255);
    color[2] = 0;
  }
  else if(newHat/hatAverage > 1.15){
    color[0] = map(newHat, 100, 1023, 200, 255);
    color[1] = map(newHat, 100, 1023, 0, 100) ;
    color[2] = map(newHat, 100, 1023, 0, 50);
  }
  else if(newBass/bassAverage < 1 || newSnare/snareAverage < 1 || newHat/hatAverage < 1){
    color[0] = 0;
    color[1] = 0;
    color[2] = 0; 
  }

//updates the bass, snare and hat volume peak arrays
  bass[frame] = newBass;
  snare[frame] = newSnare;
  hat[frame] = newHat;
  frame++; 
  if(frame>=frames){
    frame = 0;
  }

  return color;
} 

void loop(){
  resetOutputWave();
  int* spectrumValue = getBandsVolumes();
  int* color = getColor(spectrumValue); 

//sets the LEDs strip color
  for(int i=0; i<numLeds; i++){
    leds[i].setRGB(color[0],color[1],color[2]);
  }  
  FastLED.show();  

}
