int endingTimeLength = 3000;

void Ending(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 10);
    
    // Ending message
    gs->words[0] = { { 10, 12, 10, 12 }, true };
    strcpy(gs->words[0].w, gs->win ? "~~So SEXXI!~~" : "..Not SEXXI..");

    // Hearts or shit depending on ending state
    for (int i = 0; i < 10; i++) {
      gs->shapes[i] = { 2, { 30 * (i % 5), 22 * (i >= 5), 
        30 * (i % 5), 22 * (i >= 5), 0, 0, millis() }, 0, 0, true };
      if (gs->win) {
        gs->shapes[i].width = 5;
        gs->shapes[i].height = 4;
      } else {
        gs->shapes[i].width = 8;
        gs->shapes[i].height = 8;
      }
      for (int j = 0; j < gs->shapes[i].height; j++) {
        for (int k = 0; k < gs->shapes[i].width; k++) {
          gs->shapes[i].bmp[j][k] = gs->win ? LOVE[j][k] : GOOSE_POOP[j][k];
        }
      }
    }
    
    endingTimeLength = 3000;
    UpdateGlobalElapsedTime();

    gs->needsReset = false;
  }

  endingTimeLength -= GetGlobalElapsedTime();
  UpdateGlobalElapsedTime();

  if (endingTimeLength < 0) {
    gs->state = SELECTION;
  }
  if (gs->state != ENDING) {
    Reset(gs);
  }
}
