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

// Move mouse pointer every 30 seconds. Blink every 5 seconds.
void loop() {
  // If not using plentiful DigiMouse.delay(), make sure to call
  // DigiMouse.update() at least every 50ms

  DigiMouse.moveX(10); //right 10
  ledOn();
  DigiMouse.delay(100);
  
  DigiMouse.moveX(-10); //left 10
  ledOff();
  DigiMouse.delay(5000);

  for (int i = 0; i < 5; i++) {
    ledOn();
    DigiMouse.delay(50);
    ledOff();
    DigiMouse.delay(5000);
  }
}
