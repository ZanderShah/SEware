int order[TOTAL_LEVELS];
GameState room;

void Party(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    gs->selected = 0;
    
    for (int i = 3; i < TOTAL_LEVELS; i++)
      order[i] = i;
    for (int i = 3; i < TOTAL_LEVELS; i++) {
      int j = rand() % (TOTAL_LEVELS - 3) + 3;
      int t = order[i];
      order[i] = order[j];
      order[j] = order[i];
    }

    gs->needsReset = false;
  }

  (*level)[order[gs->selected]](obi, &room);
  if (room.needsReset) {
    gs->selected++;
  }

  if (gs->selected == TOTAL_LEVELS) {
    Reset(gs);
  }
}

