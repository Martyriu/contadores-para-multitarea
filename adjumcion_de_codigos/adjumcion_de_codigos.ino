/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/
byte cont1 = 0;
byte cont2 = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  int sensorVal2 = digitalRead(3);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == LOW) {
    cont1 += 1;
    if (cont1 == 1) digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    if (cont1 == 2) {
      cont1 = 0;
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }

  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (sensorVal2 == LOW) {
    cont2 += 1;
    if (cont2 == 1) digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    if (cont2 == 2) {
      cont2 = 0;
      digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    }
  } else {
    digitalWrite(12, LOW);
  }
  delay(100);
}
