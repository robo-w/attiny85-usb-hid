/**
 * Copyright 2022 Robert Wittek
 *
 * Licensed under MIT license.
 */

#include <DigiMouse.h>

void setup() {
  pinMode(1, OUTPUT);

  DigiMouse.begin();
}

void ledOn() {
  digitalWrite(1, HIGH);
}

void ledOff() {
  digitalWrite(1, LOW);
}

void loop() {
  // If not using plentiful DigiMouse.delay(), make sure to call
  // DigiMouse.update() at least every 50ms

  DigiMouse.moveX(50);
  ledOn();
  DigiMouse.delay(1000);
  
  DigiMouse.moveY(50);
  ledOff();
  DigiMouse.delay(1000);
  
  DigiMouse.moveX(-50);
  ledOn();
  DigiMouse.delay(1000);
  
  DigiMouse.moveY(-50);
  ledOff();
  DigiMouse.delay(1000);
}
