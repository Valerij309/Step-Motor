#include <CustomStepper.h>


CustomStepper stepper(8, 9, 10, 11);
int value = 0;
unsigned long timer1 = 0;
void setup() {
    stepper.rotate();
    Serial.begin(9600);
    pinMode(6,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
}

void loop() {
  int buttonCW = digitalRead(6);
  int buttonCCW = digitalRead(5);

  if (buttonCW == LOW && buttonCCW == HIGH) {
    stepper.setDirection(CW);
  }
  else if (buttonCCW == LOW && buttonCW == HIGH) {
    stepper.setDirection(CCW);
  }
  value = map(analogRead(A0),0,1023,1,17);
  stepper.setRPM(value);
  stepper.run();
 
}