#include <Servo.h>
//joystick pins
#define joyX A0
#define joyY A1
//servo pins
Servo bottom;
Servo top; 
int bottompin = 4;
int toppin = 3;
//laser pin
int laserpin = 8;
//button pin and state
int analogbuttonpin = 7;
int buttonState;
bool on = false;

void setup() {

  //for laser
  pinMode(laserpin, OUTPUT);
  //for servos
  bottom.attach(bottompin);
  top.attach(toppin);
  //for button
  pinMode(analogbuttonpin, INPUT_PULLUP);
}

void loop() {
  //This turns the laser on or off whenever the button is pressed
  buttonState = digitalRead(analogbuttonpin);
  if (buttonState == LOW ) {
    if (on == false) {
      digitalWrite(laserpin, HIGH);
      on = true;
      delay(15);
    } else {
      digitalWrite(laserpin, LOW);
      on = false;
      delay(15);
    }

  }

 
  //This converts the joystick values to the servo angles
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
  float conversion = 1023/180;
  int bottomangle = xValue / conversion; 
  int topangle = yValue / conversion;
  bottomangle = 180 - bottomangle;
  topangle = 180 - topangle;

  //prevents laser from pointing too low
  if (topangle < 30) {
    topangle = 30;
  }
  //moves servos
  bottom.write(bottomangle);
  top.write(topangle);

  

}
