void Selection(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 3, 1);

    gs->words[0] = { { 0, 0 }, true };
    gs->words[1] = { { 0, 10 }, true };
    gs->words[2] = { { 0, 20 }, true };

    gs->shapes[0] = { 2, { 0, 0, 0, 0, 0, 10, millis() }, 0, 0, false };

    gs->needsReset = false;
  }

  UpdatePosition(&(gs->shapes[0].pos));
  if (gs->shapes[0].pos.y > SCREEN_HEIGHT) {
    gs->shapes[0].pos.y = 0;
    gs->shapes[0].pos.dY = 0;
  }

  gs->streak = (int) ((obi->potential) * 8 / MAX_POTENTIAL) + 1;
  
  strcpy(gs->words[0].w, LEVEL_NAMES[gs->selected]);
  strcpy(gs->words[1].w, GAME_DETAILS[gs->selected][gs->shapes[0].pos.y >= SCREEN_HEIGHT / 2]);
  sprintf(gs->words[2].w, "Difficulty: %s", DIFFICULTY_NAMES[gs->streak - 1]);
  
  if (obi->buttons[1] && !obi->pastButtons[1]) {
    gs->selected = (gs->selected + 1) % (TOTAL_LEVELS - 1);
  }
  if (obi->buttons[0] && !obi->pastButtons[0] && gs->selected != 0) {
    gs->state = gs->selected + 1;
  } 

  if (gs->state != SELECTION) {
    Reset(gs);
  }
}
