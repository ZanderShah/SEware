int endingTimeLength = 3000;

void Ending(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 0);
    gs->words[0] = { 10, 10, true };
    strcpy(gs->words[0].w, gs->win ? "~ So SEXXI! ~" : "Not SEXXI ...");
    
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
