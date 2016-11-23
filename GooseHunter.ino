int animationTimer;

void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 5);

    gs->shapes[0] = { 2, { 0, 1, 0, 1, 20, 0, millis() }, 29, 29, true };
    for (int i = 1; i < 4; i++) {
      gs->shapes[i] = { 2, { 11, 12, 11, 12, 20, 0, millis() }, 7, 7, false };
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

    gs->shapes[4] = { 2, { 0, 5, 0, 5, 0, 0, millis() }, 21, 23, true };
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

  if (gs->shapes[0].pos.x < 0 || gs->shapes[0].pos.x + gs->shapes[0].width > SCREEN_WIDTH) {
    gs->shapes[0].pos.vX *= -1;
  }
  for (int i = 1; i < 4; i++) {
    gs->shapes[i].pos.x = gs->shapes[0].pos.x + 11;
    gs->shapes[i].pos.dX = gs->shapes[i].pos.x;
  }

  if (obi->buttons[0] && !obi->pastButtons[0] && animationTimer <= 0) {
    animationTimer = COOLDOWN;
  }
  
  if (animationTimer != 0) {
    for (int i = 1; i < 4; i++) {
      gs->shapes[i].visible = COOLDOWN * i / 3 <= animationTimer;
    }
    animationTimer--;
  } else {
    for (int i = 1; i < 4; i++) {
      gs->shapes[i].visible = false;
    }
  }

  if (gs->state != GOOSE_HUNTER) {
    Reset(gs);
  }
}
