double solution[4] = { 0 };

void LockPicker(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 1);
    gs->score = 0;

    gs->words[0] = { 0, 0, true };
    strcpy(gs->words[0].w, "PICK THE LOCKS ~");
    gs->words[1] = { 0, 20, true };
    strcpy(gs->words[1].w, "|");

    gs->shapes[0] = { 1, { 0, 20, 0, 20, 0, 0, millis() }, SCREEN_WIDTH, 1, true };


    for (int i = 0; i < 4; i++) {
      solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      while (i > 0 && fabs(solution[i] - solution[i - 1]) < 500) {
        solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      }
    }

    gs->needsReset = false;
  }

  gs->words[1].x = (int) (obi->potential / MAX_POTENTIAL * SCREEN_WIDTH);
  
  if (fabs(obi->potential - solution[gs->score]) < EPS) {
    digitalWrite(LEDS[0], HIGH);
    strcpy(gs->words[1].w, "O");
    if (obi->buttons[0] || obi->buttons[1]) {
      gs->score++;
      strcat(gs->words[0].w, "X");
    }
  } else {
    digitalWrite(LEDS[0], LOW);
    strcpy(gs->words[1].w, "|");
  }

  for (int i = 1; i < LED_COUNT; i++) {
    if (i <= gs->score) {
      digitalWrite(LEDS[i], HIGH);
    }
  }

  if (gs->score >= 4) {
    gs->state = SELECTION;
  }
  if (gs->state != LOCK_PICKER) {
    Reset(gs);
  }
}


