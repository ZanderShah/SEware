void UIsetup() {
<<<<<<< HEAD
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
    obi->pastButtons[i] = obi->buttons[i];
    obi->buttons[i] = digitalRead(BUTTONS[i]);
  }
=======
  for (int i = 0; i < SWITCH_COUNT; i++)
    pinMode(SWITCHES[i], INPUT);
  for (int i = 0; i < BUTTON_COUNT; i++)
    pinMode(BUTTONS[i], INPUT);
}

void UIloop(OrbitInput *obi) {
  for (int i = 0; i < SWITCH_COUNT; i++)
    obi->switches[i] = digitalRead(SWITCHES[i]);
  for (int i = 0; i < BUTTON_COUNT; i++)
    obi->buttons[i] = digitalRead(BUTTONS[i]);
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849
  obi->potential = analogRead(POTENTIOMETER);
}

