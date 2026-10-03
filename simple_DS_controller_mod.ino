/* Requires the NintendoExtensionCtrl library by David Madison
   https://github.com/dmadison/NintendoExtensionCtrl */

#include <NintendoExtensionCtrl.h>

//Solder a wire from each pin to the corresponding pad on the DS.

//Home is mapped to both Start and Select. This is so when using a Mayflash GameCube-to-Wii adapter, you can still soft reset. You still need to press L + R (DS) or A + B (GBA) to complete it.
//left stick = dpad
//right stick = ABXY
//ZL = L
//ZR = R

int DS_A = 2;
int DS_B = 3;
int DS_X = 4;
int DS_Y = 5;
int DS_START = 6;
int DS_SELECT = 7;
int DS_R = 8;
int DS_L = 9;
int DS_UP = 10;
int DS_RIGHT = 11;
int DS_LEFT = 12;
int DS_DOWN = 13;

const unsigned long Reconnect_Interval = 500;
unsigned long Last_Reconnect = 0;

ClassicController classic;

void press(int pin, bool pressed) {
  if (pressed) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  } else {
    pinMode(pin, INPUT);
  }
}

void releaseAll() {
  for (int pin = 2; pin <= 13; pin++) pinMode(pin, INPUT);
}

void setup() {
  releaseAll();
  classic.begin();
  classic.setHighRes(true);
}

void loop() {

  if (!classic.update()) {
    releaseAll();
    if (millis() - Last_Reconnect >= Reconnect_Interval) {
      Last_Reconnect = millis();
      classic.connect();
    }
    return;
  }

  press(DS_A, classic.buttonA());
  press(DS_B, classic.buttonB());
  press(DS_X, classic.buttonX());
  press(DS_Y, classic.buttonY());
  press(DS_L, classic.buttonZL() || classic.triggerL() > 100);
  press(DS_R, classic.buttonZR() || classic.triggerR() > 100);
  press(DS_UP, classic.dpadUp() || classic.leftJoyY() > 180);
  press(DS_DOWN, classic.dpadDown() || classic.leftJoyY() < 70);
  press(DS_LEFT, classic.dpadLeft() || classic.leftJoyX() < 70);
  press(DS_RIGHT, classic.dpadRight() || classic.leftJoyX() > 180);
  press(DS_START, classic.buttonStart() || classic.buttonPlus() || classic.buttonHome());
  press(DS_SELECT, classic.buttonSelect() || classic.buttonMinus() || classic.buttonHome());
}