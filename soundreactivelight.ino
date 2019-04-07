//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 14 //PB6
#define GREEN 15 //PB7
#define RED 19 //PB2
#define delayTime 10
#include "Ultrasonic.h"
/* Macro Define */

#define ULTRASONIC_PIN    36             /* pin of the Ultrasonic Ranger */
#define BUZZER_PIN        39 
#define LIGHT_SENSOR      26
/* Global Variables */

Ultrasonic ultrasonic(ULTRASONIC_PIN);    /* Ultrasonic Ranger object */
int distance = 0;                         /* variable to store the distance to obstacles in front */
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
int i;
int analog_value = 0;
/* the setup() method runs once, when the sketch starts */

void setup()
{
Serial.begin(9600);
pinMode(BUZZER_PIN, OUTPUT); 
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
Serial.println(0);
}

// define variables
int redValue;
int greenValue;
int blueValue;

void playTone(int tone, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(tone/5);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(tone/5);
  }
}

// main loop
void loop()
{

distance = ultrasonic.MeasureInCentimeters();   /* read the value from the sensor */  
Serial.println(distance);
    i = distance / 10;
    if (i >= 7){
      i = 7;
      }
    playTone(tones[i], 300);
    if(tones[i] == 1915){
      redValue = 255;
      blueValue = 0;
      greenValue = 0;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1700){
      redValue = 255;
      blueValue = 0;
      greenValue = 130;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1519){
      redValue = 255;
      blueValue = 0;
      greenValue = 255;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1432){
      redValue = 0;
      blueValue = 0;
      greenValue = 255;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1275){
      redValue = 0;
      blueValue = 250;
      greenValue = 0;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1136){
      redValue = 80;
      blueValue = 150;
      greenValue = 0;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 1014){
      redValue = 255;
      blueValue = 140;
      greenValue = 0;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    if(tones[i] == 956){
      redValue = 250;
      blueValue = 250;
      greenValue = 250;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
    }
    analog_value = analogRead(LIGHT_SENSOR);
    while (analog_value < 800){
      delay(30);
      analog_value = analogRead(LIGHT_SENSOR);
      }
      
}
