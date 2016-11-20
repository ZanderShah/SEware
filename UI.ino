void UIsetup() {
  for (int i = 0; i < SWITCH_COUNT; i++) {
    pinMode(SWITCHES[i], INPUT);
  }
  for (int i = 0; i < BUTTON_COUNT; i++) {
    pinMode(BUTTONS[i], INPUT);
  }
}

void UIloop(OrbitInput *obi) {
  for (int i = 0; i < SWITCH_COUNT; i++) {
    obi->switches[i] = digitalRead(SWITCHES[i]);
  }
  for (int i = 0; i < BUTTON_COUNT; i++) {
    obi->buttons[i] = digitalRead(BUTTONS[i]);
  }
  obi->potential = analogRead(POTENTIOMETER);
}

