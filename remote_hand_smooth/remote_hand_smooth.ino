

#include <Servo.h>

int thumb = 0;            // the sensor value
int sensorMin1 = 1023;    // maximum sensor value    
int sensorMax1 = 0;       // minimum sensor value

int index = 0;            // the sensor value
int sensorMin2 = 1023;    // maximum sensor value
int sensorMax2 = 0;       // minimum sensor value

int middle = 0;           // the sensor value
int sensorMin3 = 1023;    // maximum sensor value
int sensorMax3 = 0;       // minimum sensor value

int pinkie = 0;           // the sensor value
int sensorMin4 = 1023;    // maximum sensor value
int sensorMax4 = 0;       // minimum sensor value

Servo myservo1;   // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int potpin = 0;   // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int potpin3 = 2;  // analog pin used to connect the potentiometer
int potpin4 = 3;  // analog pin used to connect the potentiometer

int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int val3;    // variable to read the value from the analog pin
int val4;    // variable to read the value from the analog pin

bool dot = false;


const int val1numReadings = 10;

int val1readings[val1numReadings];      // the readings from the analog input
int val1readIndex = 0;              // the index of the current reading
int val1total = 0;                  // the running total
int val1average = 0;                // the average

const int val2numReadings = 10;

int val2readings[val2numReadings];      // the readings from the analog input
int val2readIndex = 0;              // the index of the current reading
int val2total = 0;                  // the running total
int val2average = 0;                // the average

const int val3numReadings = 10;

int val3readings[val3numReadings];      // the readings from the analog input
int val3readIndex = 0;              // the index of the current reading
int val3total = 0;                  // the running total
int val3average = 0;                // the average

const int val4numReadings = 10;

int val4readings[val4numReadings];      // the readings from the analog input
int val4readIndex = 0;              // the index of the current reading
int val4total = 0;                  // the running total
int val4average = 0;                // the average


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


  myservo1.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(10);  // attaches the servo on pin 9 to the servo object

}

void loop() {

// Value 1 ---

  for (int val1thisReading = 0; val1thisReading < val1numReadings; val1thisReading++) {
    val1readings[val1thisReading] = 0;
  }
  
  val1 = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    
    // subtract the last reading:
  val1total = val1total - val1readings[val1readIndex];
  // read from the sensor:
  val1readings[val1readIndex] = val1;
  // add the reading to the total:
  val1total = val1total + val1readings[val1readIndex];
  // advance to the next position in the array:
  val1readIndex = val1readIndex + 1;

  // if we're at the end of the array...
  if (val1readIndex >= val1numReadings) {
    // ...wrap around to the beginning:
    val1readIndex = 0;
  }

  // calculate the average:
  val1average = val1total / val1numReadings;
  delay(1);        // delay in between reads for stability
  
  val1 = map(val1average, sensorMin1,sensorMax1, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = constrain(val1, 0, 180);

// Value 2 ---

  for (int val2thisReading = 0; val2thisReading < val2numReadings; val2thisReading++) {
    val2readings[val2thisReading] = 0;
  }

  
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)

      // subtract the last reading:
  val2total = val2total - val2readings[val2readIndex];
  // read from the sensor:
  val2readings[val2readIndex] = val2;
  // add the reading to the total:
  val2total = val2total + val2readings[val2readIndex];
  // advance to the next position in the array:
  val2readIndex = val2readIndex + 1;

  // if we're at the end of the array...
  if (val2readIndex >= val2numReadings) {
    // ...wrap around to the beginning:
    val2readIndex = 0;
  }

  // calculate the average:
  val2average = val2total / val2numReadings;
  delay(1);        // delay in between reads for stability
  
  val2 = map(val2average, sensorMin2, sensorMax2, 180, 0);     // scale it to use it with the servo (value between 0 and 180)
  val2 = constrain(val2, 0, 180);


// Value 3 ---

  for (int val3thisReading = 0; val3thisReading < val3numReadings; val3thisReading++) {
    val3readings[val3thisReading] = 0;
  }

    
  val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)

      // subtract the last reading:
  val3total = val3total - val3readings[val3readIndex];
  // read from the sensor:
  val3readings[val3readIndex] = val3;
  // add the reading to the total:
  val3total = val3total + val3readings[val3readIndex];
  // advance to the next position in the array:
  val3readIndex = val3readIndex + 1;

  // if we're at the end of the array...
  if (val3readIndex >= val3numReadings) {
    // ...wrap around to the beginning:
    val3readIndex = 0;
  }

  // calculate the average:
  val3average = val3total / val3numReadings;
  delay(1);        // delay in between reads for stability
  
  val3 = map(val3average, sensorMin3, sensorMax3, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val3 = constrain(val3, 0, 180);

// Value 4 ---

  for (int val4thisReading = 0; val4thisReading < val4numReadings; val4thisReading++) {
    val4readings[val4thisReading] = 0;
  }


  val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023)

      // subtract the last reading:
  val4total = val4total - val4readings[val4readIndex];
  // read from the sensor:
  val4readings[val4readIndex] = val4;
  // add the reading to the total:
  val4total = val4total + val4readings[val4readIndex];
  // advance to the next position in the array:
  val4readIndex = val4readIndex + 1;

  // if we're at the end of the array...
  if (val4readIndex >= val4numReadings) {
    // ...wrap around to the beginning:
    val4readIndex = 0;
  }

  // calculate the average:
  val4average = val4total / val4numReadings;
  delay(1);        // delay in between reads for stability

  
  val4 = map(val4average, sensorMin4, sensorMax3, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val4 = constrain(val4, 0, 180);


// Print out values

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

    myservo1.write(val1);                  
    myservo2.write(val2); 
    myservo3.write(val3); 
    myservo4.write(val4);
    
  delay(5);                           // waits for the servo to get there
  
}
