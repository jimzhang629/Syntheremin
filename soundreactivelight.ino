/*
Control LEDs with sound input
*/

int  sensorAnalogPin = A0;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int oldAnalogValue;          // variable to store analog value from previous loop
                             
#define RED 11
#define GREEN 10
#define BLUE 9
int redValue;
int greenValue;
int blueValue;
int i;

void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}


void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue
  digitalValue = digitalRead(sensorDigitalPin); // Read digital value from pin 7 
  Serial.println("analog");
  Serial.println(analogValue); // Send the analog value to the serial transmit interface
  Serial.println("digital");
  Serial.println(digitalValue);
  if(analogValue!=oldAnalogValue and digitalValue > 0)      // When the Sound Sensor senses a change in sound, via voltage present, change the LED to a random color
  {
      for(i=0;i<9;i++){
        redValue = random(255);
        blueValue = random(255);
        greenValue = random(1);
        analogWrite(RED,redValue);
        analogWrite(BLUE,blueValue);
        analogWrite(GREEN,greenValue);
        delay(100);
      }
  }
  oldAnalogValue = analogValue;
  
  delay(400);                  // Slight pause so that we don't overwhelm the serial interface
}
