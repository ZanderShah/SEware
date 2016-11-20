void MainMenu(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 4, 0);
    gs->numWords = 3;
    
    strcpy(gs->words[0].w, "~SEXXIWARE~");
    gs->words[0].x = 20;
    gs->words[0].y = 0;

    strcpy(gs->words[1].w, ">>TURN UP<<");
    gs->words[1].x = 20;
    gs->words[1].y = 10;

    gs->words[2].x = 5;
    gs->words[2].y = 20;

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
