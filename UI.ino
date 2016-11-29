TwoWire orbitWire(0);

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
  orbitWire.begin();
  WireWriteRegister(ACCELEROMETER, 0x31, 1);
  WireWriteRegister(ACCELEROMETER, 0x2D, 1 << 3);
}

// From Rollen's RPS project
// Slightly modified to work with how we manage input
void ShakeTick(OrbitInput *obi) {
  uint32_t data[DATA_LENGTH] = { 0 };
  
  WireWriteByte(ACCELEROMETER, 0x32);
  WireRequestArray(ACCELEROMETER, data, DATA_LENGTH);

  uint16_t xi = (data[1] << 8) | data[0];
  uint16_t yi = (data[3] << 8) | data[2];
  uint16_t zi = (data[5] << 8) | data[4];
  float x = *(int16_t*)(&xi) / MAXIMUM_READING * MAXIMUM_ACCELERATION;
  float y = *(int16_t*)(&yi) / MAXIMUM_READING * MAXIMUM_ACCELERATION;
  float z = *(int16_t*)(&zi) / MAXIMUM_READING * MAXIMUM_ACCELERATION;
  
  obi->shake = sqrt(x*x + y*y + z*z);
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
  ShakeTick(obi);
}


