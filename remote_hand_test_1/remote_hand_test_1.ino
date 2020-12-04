/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

int thumb = 0;         // the sensor value
int sensorMin1 = 1023;        // minimum sensor value
int sensorMax1 = 0;

int index = 0;         // the sensor value
int sensorMin2 = 1023;        // minimum sensor value
int sensorMax2 = 0;

int middle = 0;         // the sensor value
int sensorMin3 = 1023;        // minimum sensor value
int sensorMax3 = 0;

int pinkie = 0;         // the sensor value
int sensorMin4 = 1023;        // minimum sensor value
int sensorMax4 = 0;

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int potpin3 = 2;  // analog pin used to connect the potentiometer
int potpin4 = 3;  // analog pin used to connect the potentiometer

int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int val3;    // variable to read the value from the analog pin
int val4;    // variable to read the value from the analog pin

bool dot = false;


void setup() {

   Serial.begin(9600);

   while (!Serial) delay(1);
   
   Serial.println("Calibrating");

   pinMode(13, OUTPUT);

   while (millis() < 5000) {

  
   digitalWrite(13, HIGH);
  

    thumb = analogRead(potpin);

    // record the maximum sensor value
    if (thumb > sensorMax1) {
      sensorMax1 = thumb;
    }

    // record the minimum sensor value
    if (thumb < sensorMin1) {
      sensorMin1 = thumb;
    }

     index = analogRead(potpin2);

    // record the maximum sensor value
    if (index > sensorMax2) {
      sensorMax2 = index;
    }

    // record the minimum sensor value
    if (index < sensorMin2) {
      sensorMin2 = index;
    }

    middle = analogRead(potpin3);

    // record the maximum sensor value
    if (middle > sensorMax3) {
      sensorMax3 = middle;
    }

    // record the minimum sensor value
    if (middle < sensorMin3) {
      sensorMin3 = middle;
    }

     pinkie = analogRead(potpin4);

    // record the maximum sensor value
    if (pinkie > sensorMax4) {
      sensorMax4 = pinkie;
    }

    // record the minimum sensor value
    if (pinkie < sensorMin4) {
      sensorMin4 = pinkie;
    }


      digitalWrite(13, LOW);




  }
  
  Serial.println("Calibration finished");

  delay (2000);


  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(10);  // attaches the servo on pin 9 to the servo object

}

void loop() {

 
  
  val1 = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, sensorMin1,sensorMax1, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = constrain(val1, 0, 180);


  
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, sensorMin2, sensorMax2, 180, 0);     // scale it to use it with the servo (value between 0 and 180)
  val2 = constrain(val2, 0, 180);

    
  val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, sensorMin3, sensorMax3, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val3 = constrain(val3, 0, 180);


  val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023)
  val4 = map(val4, sensorMin4, sensorMax3, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val4 = constrain(val4, 0, 180);


  Serial.print("thumb : ");
  Serial.print(val2);
  Serial.print("   ");
  Serial.print("Index : ");
  Serial.print(val1);
  Serial.print("   ");
  Serial.print("Middle : ");
  Serial.print(val3);
  Serial.print("   ");
  Serial.print("Pinkie : ");
  Serial.println(val4);

    myservo.write(val1);                  
    myservo2.write(val2); 
    myservo3.write(val3); 
    myservo4.write(val4);
  delay(5);                           // waits for the servo to get there
  
}
