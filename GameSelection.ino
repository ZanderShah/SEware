void Selection(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 0);
    
    strcpy(gs->words[0].w, "GAME SELECTION");
    gs->words[0].x = 0;
    gs->words[0].y = 0;
    
    gs->words[1].x = 0;
    gs->words[1].y = 10;

    gs->needsReset = false;
  }

  strcpy(gs->words[1].w, LEVEL_NAMES[gs->selected]);

  if (obi->buttons[1] && obi->buttons[1] ^ obi->pastButtons[1]) {
    gs->selected = (gs->selected + 1) % (sizeof(LEVEL_NAMES) / sizeof(LEVEL_NAMES[0]));
  }
  if (obi->buttons[0] && obi->buttons[0] ^ obi->pastButtons[0]) {
    gs->state = gs->selected + 2;
  } 

  if (gs->state != SELECTION) {
    Reset(gs);
  }
}
