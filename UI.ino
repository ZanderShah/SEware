void UIsetup() {
  for (int i = 0; i < SWITCH_COUNT; i++) {
    pinMode(SWITCHES[i], INPUT);
  }
  for (int i = 0; i < BUTTON_COUNT; i++) {
    pinMode(BUTTONS[i], INPUT);
  }
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void UIloop(OrbitInput *obi) {
  for (int i = 0; i < SWITCH_COUNT; i++) {
    obi->switches[i] = digitalRead(SWITCHES[i]);
  }
  for (int i = 0; i < BUTTON_COUNT; i++) {
    obi->pastButtons[i] = obi->buttons[i];
    obi->buttons[i] = digitalRead(BUTTONS[i]);
  }
  obi->potential = analogRead(POTENTIOMETER);
}

