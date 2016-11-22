int animationTimer;

void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 3);

    for (int i = 0; i < 3; i++) {
      gs->shapes[i] = { 2, { 0, 1, 0, 1, 20, 0, millis() }, 29, 29, true };
    }
    gs->shapes[1].visible = false;
    gs->shapes[2].visible = false;
   
    for (int i = 0; i < gs->shapes[0].height; i++) {
      for (int j = 0; j < gs->shapes[0].width; j++) {
        gs->shapes[0].bmp[i][j] = NO_FIRE[i][j];
        gs->shapes[1].bmp[i][j] = MED_FIRE[i][j];
        gs->shapes[2].bmp[i][j] = FULL_FIRE[i][j];
      }
    }
    
    gs->needsReset = false;
  }

  for (int i = 0; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  if (gs->shapes[0].pos.x + gs->shapes[0].width >= SCREEN_WIDTH) {
    for (int i = 0; i < 3; i++) {
      gs->shapes[i].pos.vX *= -1;
    }
  }

  if (obi->buttons[0] && !obi->pastButtons[0] && animationTimer <= 0) {
    animationTimer = COOLDOWN;
  }
  
  if (animationTimer == 0) {
    gs->shapes[0].visible = true;
    gs->shapes[1].visible = false;
    gs->shapes[2].visible = false;
  } else {
    if (abs(animationTimer) <= 75) {
      gs->shapes[0].visible = false;
      gs->shapes[1].visible = true;
      gs->shapes[2].visible = false;
    } else {
      gs->shapes[0].visible = false;
      gs->shapes[1].visible = false;    
      gs->shapes[2].visible = true;
    }
    animationTimer--;
  }

  if (gs->state != GOOSE_HUNTER) {
    Reset(gs);
  }
}
