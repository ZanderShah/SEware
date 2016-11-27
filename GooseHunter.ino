int animationTimer;

void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 5);
    gs->score = 0;
    gs->lives = 10;

    gs->words[0] = { { 0, 0, 0, 0 }, true };
    
    gs->shapes[0] = { 2, { 0, 1, 0, 1, 100 + 25 * gs->streak, 0, millis() }, 29, 29, true };
    for (int i = 1; i < 4; i++) {
      gs->shapes[i] = { 2, { 11, 12, 11, 12, 0, 0, millis() }, 7, 7, false };
    }
   
    for (int i = 0; i < gs->shapes[0].height; i++) {
      for (int j = 0; j < gs->shapes[0].width; j++) {
        gs->shapes[0].bmp[i][j] = CROSSHAIR[i][j];
      }
    }
    
    for (int i = 1; i < 4; i++) {
      for (int j = 0; j < gs->shapes[i].height; j++) {
        for (int k = 0; k < gs->shapes[i].width; k++) {
          gs->shapes[i].bmp[j][k] = FIRE_ANIMATION[i - 1][j][k];
        }
      }
    }

    gs->shapes[4] = { 2, { rand() % 100, 5, 50, 5, (rand() % 2 == 0 ? 1 : -1) * 100 + 25 * gs->streak, 0, millis() }, 21, 23, true };
    for (int i = 0; i < gs->shapes[4].height; i++) {
      for (int j = 0; j < gs->shapes[4].width; j++) {
        gs->shapes[4].bmp[i][j] = BIG_GOOSE[i][j];     
      }
    }
    
    gs->needsReset = false;
  }

  for (int i = 0; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  if (gs->shapes[0].pos.x <= 0) {
    gs->shapes[0].pos.vX = 100 + 25 * gs->streak;
  } else if (gs->shapes[0].pos.x + gs->shapes[0].width >= SCREEN_WIDTH) {
    gs->shapes[0].pos.vX = -(100 + 25 * gs->streak);
  }
  if (gs->shapes[4].pos.x <= 0) {
    gs->shapes[4].pos.vX = (gs->score * 75 + 100 + 25 * gs->streak);
  } else if (gs->shapes[4].pos.x + gs->shapes[4].width >= SCREEN_WIDTH) {
    gs->shapes[4].pos.vX = -(gs->score * 75 + 100 + 25 * gs->streak);
  }
  
  for (int i = 1; i < 4; i++) {
    gs->shapes[i].pos.x = gs->shapes[0].pos.x + 11;
    gs->shapes[i].pos.dX = gs->shapes[i].pos.x;
  }

  if (((obi->buttons[0] && !obi->pastButtons[0]) || (obi->buttons[1] && !obi->pastButtons[1]) ) && animationTimer <= 0) {
    animationTimer = COOLDOWN;
    gs->lives--;
    if (intersect(gs->shapes[4], gs->shapes[2])) {
      gs->score++;
      gs->shapes[4].pos.vX = (gs->score * 75 + 100 + 25 * gs->streak);
    }
  }
  
  if (animationTimer != 0) {
    gs->shapes[0].pos.frozen = true;
    for (int i = 1; i < 4; i++) {
      gs->shapes[4 - i].visible = animationTimer >= COOLDOWN * (i - 1) / 3;
    }
    animationTimer--;
  } else {
    gs->shapes[0].pos.frozen = false;
    for (int i = 1; i < 4; i++) {
      gs->shapes[i].visible = false;
    }
  }

  sprintf(gs->words[0].w, "Ammo: %d", gs->lives);

  for (int i = 1; i < LED_COUNT; i++) {
    if (i <= gs->score) {
      digitalWrite(LEDS[i], HIGH);
    } else {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if (gs->score >= 4 || gs->lives <= 0) {
    gs->state = ENDING;
    gs->win = gs->score >= 4;
  }

  if (gs->state != GOOSE_HUNTER) {
    for (int i = 0; i < LED_COUNT; i++) {
      digitalWrite(LEDS[i], LOW);
    }
    Reset(gs);
  }
}
