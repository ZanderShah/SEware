double solution[4] = { 0 };

int timeLeft = 30000;
int maxTime = 30000;

void LockPicker(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 2);
    gs->score = 0;

    gs->words[0] = { { 0, 0, 0, 0 }, true };
    strcpy(gs->words[0].w, "PICK THE LOCKS ~");
    gs->words[1] = { { 0, 20, 0, 20 }, true };
    strcpy(gs->words[1].w, "|");

    gs->shapes[0] = { 1, { 0, 20, 0, 20, 0, 0, millis() }, SCREEN_WIDTH, 1, true };

    // Randomly generate solutions
    for (int i = 0; i < 4; i++) {
      solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      while (i > 0 && fabs(solution[i] - solution[i - 1]) < 500) {
        solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      }
    }

    // Time remaining bar
    gs->shapes[1] = { 1, { 0, 10, 0, 10, 0, 0, millis() }, SCREEN_WIDTH, 2, true };

    maxTime = 30000 - 3250 * gs->streak;
    timeLeft = 30000 - 3250 * gs->streak;
    gs->needsReset = false;
    UpdateGlobalElapsedTime();
  }

  gs->words[1].pos.x = (int) (obi->potential / MAX_POTENTIAL * SCREEN_WIDTH);
  
  if (fabs(obi->potential - solution[gs->score]) < EPS) {
    digitalWrite(LEDS[0], HIGH);
    strcpy(gs->words[1].w, "O");
    if ((obi->buttons[0] && !obi->pastButtons[0]) || (obi->buttons[1] && !obi->pastButtons[1])) {
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

  gs->shapes[1].width = ((double) timeLeft / maxTime) * SCREEN_WIDTH;

  timeLeft -= GetGlobalElapsedTime();
  UpdateGlobalElapsedTime();

  if (timeLeft < 0 || gs->score >= 4) {
    gs->state = ENDING;
    gs->win = gs->score >= 4;
  }

  if (gs->state != LOCK_PICKER) {
    Reset(gs);
  }

  
}


