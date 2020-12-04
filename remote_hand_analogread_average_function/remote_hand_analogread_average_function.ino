/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
    int pin = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int smoothValue = averageVal(A1);

  // print out the value you read:
  Serial.print(sensorValue2 );
  Serial.print(" ");
  Serial.println(smoothValue);
  delay(1);        // delay in between reads for stability
}

int averageVal(int pin){
  int i;
  long sval = 0;

  for (i = 0; i < 50; i++){
    sval = sval + analogRead(pin);    // sensor on analog pin 0
  }

  sval = sval / 50;    // average
  return sval;
}
