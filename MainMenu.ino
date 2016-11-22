void MainMenu(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 4, 0);

    gs->words[0] = { 20, 0, true };
    strcpy(gs->words[0].w, "~SEXXIWARE~");
    gs->words[1] = { 20, 10, true };
    strcpy(gs->words[1].w, ">>TURN UP<<");
    gs->words[2] = { 5, 20, true };

    gs->needsReset = false;
  }

  if (obi->potential < HYPE_THRESHOLD) {
    strcpy(gs->words[3].w, HYPE[0]);
  } else if (obi->potential < 2 * HYPE_THRESHOLD) {
    strcpy(gs->words[3].w, HYPE[1]);
  } else {
    strcpy(gs->words[3].w, HYPE[2]);
  }
    
  sprintf(gs->words[2].w, "%s %04g %s", gs->words[3].w, obi->potential, gs->words[3].w);

  if (obi->potential > 3 * HYPE_THRESHOLD) {
    gs->state = SELECTION;
    gs->selected = 0;
  }

  if (gs->state != MAIN_MENU) {
    Reset(gs);
  }
}
