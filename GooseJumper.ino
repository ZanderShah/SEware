Shape CreateJumpObject(int difficulty) {
  int tx = rand() % 50 + 130;
  Shape ret = { 2, { tx, 22, tx, 22, -20 - 7 * difficulty, 0, millis() }, 10, 8, true };
  int retWidth, retHeight;
  
  if (rand() % 2 == 1) {
    ret.width = 10;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 10; c++) {
        ret.bmp[r][c] = SMALL_GOOSE[r][c];
      }
    }
  } else { 
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        ret.bmp[r][c] = GOOSE_POOP[r][c];
      }
    }
  }
  return ret;  
}

int levelLength = 1000;

void GooseJumper(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 6);
    
    // Ground
    gs->shapes[0] = { 1, { 0, 31, 0, 31, 0, 0, millis() }, 150, 3, true };
    // Goose
    gs->shapes[1] = { 2, { 150, 22, 150, 22, -20 - 7 * gs->streak, 0, millis() }, 10, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 10; c++) {
        gs->shapes[1].bmp[r][c] = SMALL_GOOSE[r][c];
      }
    }

    // Goose Poop
    gs->shapes[2] = { 2, { 225, 22, 225, 22, -20 - 7 * gs->streak, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        gs->shapes[2].bmp[r][c] = GOOSE_POOP[r][c];
      }
    }
  
    // Player
    gs->shapes[3] = { 2, { 48, 22, 48, 22, 0, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        gs->shapes[3].bmp[r][c] = JUMP_PLAYER[r][c];
      }
    }

    // Finish bar
    gs->shapes[4] = { 2, { levelLength, 22, levelLength, 22, -20 - 7 * gs->streak, 0, millis() }, 100, 20, false };

    //Progress bar
    gs->shapes[5] = { 1, { 0, 0, 0, 0, 0, 0, millis() }, 0, 2, true };
    gs->needsReset = false;
    
  }

  if ((obi->buttons[0] || obi->buttons[1]) && fabs(gs->shapes[3].pos.aY) < 0.01) {
    gs->shapes[3].pos.aY = 60 + 15 * gs->streak;
    gs->shapes[3].pos.vY = -40 - 4 * gs->streak;
  }

  if (gs->shapes[3].pos.y >= 24){
    gs->shapes[3].pos.y = 22;
    gs->shapes[3].pos.dY = 22;
    gs->shapes[3].pos.aY = 0;
    gs->shapes[3].pos.vY = 0;
  }

  // Update obstacles
  for (int i = 1; i <= 2; i++){
    if (gs->shapes[i].pos.x + gs->shapes[i].width < 0){
      gs->shapes[i] = CreateJumpObject(gs->streak);
    }
  }

  // Collision detection
  for (int i = 1; i <= 2; i++){
    if (intersect(gs->shapes[i], gs->shapes[3])){
      gs->state = ENDING;
      gs->win = false;
    }
  }

  // Update progress bar
  gs->shapes[5].width = (int) ((levelLength - gs->shapes[4].pos.dX) / levelLength * 128.0);

  if (gs->shapes[5].width >=128){
    gs->state = ENDING;
    gs->win = true;
  }
  
  if (gs->state != GOOSE_JUMPER) {
    Reset(gs);
  }
}


