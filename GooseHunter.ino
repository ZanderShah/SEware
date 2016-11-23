int animationTimer;

Shape CreateGoose(int score) {
  Shape ret = { 2, { rand() % 100, 5, 50, 5, (rand() % 2 == 0 ? 1 : -1) * (score * 75 + 100) * 2, 0, millis() }, 21, 23, true };
  ret.pos.dX = ret.pos.x;
  for (int i = 0; i < ret.height; i++) {
    for (int j = 0; j < ret.width; j++) {
      ret.bmp[i][j] = BIG_GOOSE[i][j];     
    }
  }
  return ret;
}

void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 5);
    gs->score = 0;

    gs->shapes[0] = { 2, { 0, 1, 0, 1, 300, 0, millis() }, 29, 29, true };
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

    gs->shapes[4] = CreateGoose(gs->score);
    
    gs->needsReset = false;
  }

  for (int i = 0; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  if (gs->shapes[0].pos.x <= 0) {
    gs->shapes[0].pos.vX = 300;
  } else if (gs->shapes[0].pos.x + gs->shapes[0].width >= SCREEN_WIDTH) {
    gs->shapes[0].pos.vX = -300;
  }
  if (gs->shapes[4].pos.x <= 0) {
    gs->shapes[4].pos.vX = (gs->score * 75 + 100) * 2;
  } else if (gs->shapes[4].pos.x + gs->shapes[4].width >= SCREEN_WIDTH) {
    gs->shapes[4].pos.vX = -(gs->score * 75 + 100) * 2;
  }
  
  for (int i = 1; i < 4; i++) {
    gs->shapes[i].pos.x = gs->shapes[0].pos.x + 11;
    gs->shapes[i].pos.dX = gs->shapes[i].pos.x;
  }

  if (obi->buttons[0] && !obi->pastButtons[0] && animationTimer <= 0) {
    animationTimer = COOLDOWN;
    if (intersect(gs->shapes[4], gs->shapes[2])) {
      gs->score++;
      gs->shapes[4] = CreateGoose(gs->score);
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

  for (int i = 1; i < LED_COUNT; i++) {
    if (i <= gs->score) {
      digitalWrite(LEDS[i], HIGH);
    } else {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if (gs->score >= 4) {
    gs->state = MAIN_MENU;
  }

  if (gs->state != GOOSE_HUNTER) {
    for (int i = 0; i < LED_COUNT; i++) {
      digitalWrite(LEDS[i], LOW);
    }
    Reset(gs);
  }
}
