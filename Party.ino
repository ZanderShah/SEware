int order[TOTAL_LEVELS];

void Party(OrbitInput *obi, GameState *gs) {
  if (gs->partyReset) {
    for (int i = 3; i < TOTAL_LEVELS; i++)
      order[i] = i;
    for (int i = 3; i < TOTAL_LEVELS; i++) {
      int j = rand() % (TOTAL_LEVELS - 3) + 3;
      int t = order[i];
      order[i] = order[j];
      order[j] = t;
    }
    gs->selected = 3;
    gs->partyReset = false;
  }
  
  gs->state = order[gs->selected];
  (*level[gs->state])(obi, gs);
  gs->state = PARTY;

  if (gs->needsReset) {
    gs->selected++;
  }

  if (gs->selected == TOTAL_LEVELS) {
    gs->state = MAIN_MENU;
    gs->partyReset = true;
    Reset(gs);
  }
}

