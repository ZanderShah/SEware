void Selection(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 0);

    gs->words[0] = { 0, 0, true };
    strcpy(gs->words[0].w, "GAME SELECTION");
    gs->words[1] = { 0, 10, true };

    gs->needsReset = false;
  }

  strcpy(gs->words[1].w, LEVEL_NAMES[gs->selected]);

  if (obi->buttons[1] && !obi->pastButtons[1]) {
    gs->selected = (gs->selected + 1) % (TOTAL_LEVELS - 2);
  }
  if (obi->buttons[0] && !obi->pastButtons[0]) {
    gs->state = gs->selected + 2;
  } 

  if (gs->state != SELECTION) {
    Reset(gs);
  }
}
