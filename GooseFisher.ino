int currentWater = 1;
int timeElapsed = 0;
int timeToFish = 0;
int fishCatchInterval = 1100;

void GooseFisher(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 5);

    // Ending message
    gs->words[0] = { { 0, 0, 0, 0 }, false };
    strcpy(gs->words[0].w, "Caught!");
    
    // Fisherman
    gs->shapes[0] = { 2, { 16, 8, 16, 8, 0, 0, millis(),0,0 }, 16, 16, true };
    for (int r = 0; r < 16; r++) {
      for (int c = 0; c <16; c++) {
        gs->shapes[0].bmp[r][c] = FISHER_MAN[r][c];
      }
    }
    
    // Fishing line
    gs->shapes[1] = { 2, { 32, 0, 32, 0, 0, 0, millis(),0,0 }, 32, 24, true };
    for (int r = 0; r < 24; r++) {
      for (int c = 0; c <32; c++) {
        gs->shapes[1].bmp[r][c] = FISHING_LINE[r][c];
      }
    }

    // Water
    gs->shapes[2] = { 2, { 48, 0, 48, 0, 0, 0, millis(), 0 ,0 }, 32, 32, true };
    for (int r = 0; r < 32; r++) {
      for (int c = 0; c < 32; c++) {
        gs->shapes[2].bmp[r][c] = WATER1[r][c];
      }
    }

    // Fish bite
    gs->shapes[3] = { 2, { 60, 15, 60, 15, 0, 0, millis(), 0 ,0 }, 8, 8, false };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        gs->shapes[3].bmp[r][c] = FISH_BITE[r][c];
      }
   }

    // Fish
    gs->shapes[4] = { 2, { 58, 15, 58, 15, 0, 0, millis(), 0, 0 }, 12, 8, false };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 12; c++) {
        gs->shapes[4].bmp[r][c] = FISH[r][c];
      }
    }
    
    timeToFish = rand() % 6000 + 3500 - 400 * gs->streak;
    fishCatchInterval = 1000 - 75 * gs->streak;
    timeElapsed = 0;
    gs->needsReset = false;
    UpdateGlobalElapsedTime();
    gs->score = 0;
  }
  
  timeElapsed += GetGlobalElapsedTime();
  
  if (timeElapsed >= 500) {
    timeElapsed = 0;
    if (currentWater == 1) {
      currentWater = 2;
      for (int r = 0; r < 32; r++) {
        for (int c = 0; c < 32; c++) {
          gs->shapes[2].bmp[r][c] = WATER2[r][c];
        }
      }
    } else {
      currentWater = 1;
      for (int r = 0; r < 32; r++) {
        for (int c = 0; c < 32; c++) {
          gs->shapes[2].bmp[r][c] = WATER1[r][c];
        }
      }
    }
  }


  if (gs->score == 0) {
    if (timeToFish >= 0) {
      timeToFish -= GetGlobalElapsedTime();
    } else {
      fishCatchInterval -= GetGlobalElapsedTime();
      gs->shapes[3].visible = true;
    }
  
    if (fishCatchInterval < 0) {
      gs->state = ENDING;
      gs->win = false;
    }
  
    if (obi->shake >= SHAKE_THRESHOLD && timeToFish < 0) {
      gs->score++;
      gs->words[0].visible = true;
      gs->shapes[4].visible = true;
      gs->shapes[3].visible = false;
      gs->shapes[4].pos.vX =- 15;
    } else if (obi->shake >= SHAKE_THRESHOLD && timeToFish > 0){
      gs->state = ENDING;
      gs->win = false;
    }
  } else {
    if (gs->shapes[4].pos.x <= 10) {
      gs->shapes[4].pos.vX = 0;
      gs->state = ENDING;
      gs->win = true;
    }
  }

  UpdateGlobalElapsedTime();
  
  if (gs->state != GOOSE_FISHER) {
    Reset(gs);
  }
}


