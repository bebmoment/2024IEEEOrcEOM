/*
 * Arduino Leonardo that plays level 3 of run 2 upon shorting 5 to GND
 * works on a non-fullscreen window, high frame rate, high quality, and normal speed, because those matter.
 * as part of Arduino club's demo
 * Contributors: Ben Wang and James Graves
 */

#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(LOW==digitalRead(5)) {
    pressAndRelease('r', 63, 1094);
    jumpAndRelease(547, 796);
    jumpAndRelease(313,844);
    jumpAndRelease(250, 531);
    jumpAndRelease(391, 343);
    jumpAndRelease(344, 469);
    jumpAndRelease(547, 1922);
  }
}

void jumpAndRelease(int holdTime, int releaseTime) {
  pressAndRelease(' ', holdTime, releaseTime);
}

void pressAndRelease(char key, int holdTime, int releaseTime) {
  Keyboard.press(key);
  delay(holdTime);
  Keyboard.releaseAll();
  delay(releaseTime);
}

void pressKey(char key, int holdTime) {
  Keyboard.press(key);
  delay(holdTime);
}

void pressNothing(int forHowLong) {
  Keyboard.releaseAll();
  delay(forHowLong);
}
