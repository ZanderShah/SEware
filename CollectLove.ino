Shape CreateLoveShape(int difficulty) {
  Shape ret = { 2, { -rand() % 300, rand() % 26, 0, 0, rand() % 30 + 15 + 5 * difficulty, 0, millis() }, 5, 4, true };
  ret.pos.dX = ret.pos.x;
  ret.pos.dY = ret.pos.y;
  for (int i = 0; i < ret.height; i++) {
    for (int j = 0; j < ret.width; j++) {
      ret.bmp[i][j] = LOVE[i][j];
    }
  }
  return ret;
}

void CollectLove(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 10);
    gs->score = 0;
    gs->lives = 4;

    gs->words[0] = { { 0, 0, 0, 0 }, true };

    gs->shapes[0] = { 1, { 120, 0, 120, 0, 0, 0, millis() }, 0, 32, true };
    gs->shapes[1] = { 2, { 115, 10, 115, 10, 0, 0, millis() }, 5, 5, true };
    for (int i = 0; i < gs->shapes[1].height; i++) {
      for (int j = 0; j < gs->shapes[1].width; j++) {
        gs->shapes[1].bmp[i][j] = BASKET[i][j];
      }
    }
    for (int i = 2; i < gs->numShapes; i++) {
      gs->shapes[i] = CreateLoveShape(gs->streak);
    }

    gs->needsReset = false;
  }

  gs->shapes[1].pos.x = (int) ((obi->potential / MAX_POTENTIAL) * SCREEN_WIDTH);
  gs->shapes[1].pos.dX = gs->shapes[1].pos.x;

  gs->shapes[1].pos.vY = 0;
  if (obi->buttons[0] && gs->shapes[1].pos.y + gs->shapes[1].height < 32) {
    gs->shapes[1].pos.vY = 30;
  } else if (obi->buttons[1] && gs->shapes[1].pos.y > 0) {
    gs->shapes[1].pos.vY = -30;
  }

  for (int i = 2; i < gs->numShapes; i++) {
    if (intersect(gs->shapes[1], gs->shapes[i])) {
      gs->score++;
      gs->shapes[i] = CreateLoveShape(gs->streak);
    }
    if (gs->shapes[i].pos.x + gs->shapes[i].width > SCREEN_WIDTH) {
      gs->lives--;
      gs->shapes[i] = CreateLoveShape(gs->streak);
    }
  }

  for (int i = 0; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  for (int i = 1; i < LED_COUNT; i++) {
    if (i <= gs->lives) {
      digitalWrite(LEDS[i], HIGH);
    } else {
      digitalWrite(LEDS[i], LOW);
    }
  }

  sprintf(gs->words[0].w, "%02d/%d", gs->score, MAX_LOVE);

  if (gs->score >= MAX_LOVE || gs->lives < 0) {
    gs->state = ENDING;
    gs->win = gs->score >= MAX_LOVE;
  }
  
  if (gs->state != COLLECT_LOVE) {
    Reset(gs);
  }
}
