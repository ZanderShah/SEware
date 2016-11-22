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
      order[j] = t;
    }

    room.needsReset = true;
    gs->needsReset = false;
  }

  (*level)[order[gs->selected]](obi, &room);
  
  if (room.needsReset) {
    gs->selected++;
  }

  gs->numWords = room.numWords;
  gs->words = room.words;
  gs->numShapes = room.numShapes;
  gs->shapes = room.shapes;

  if (gs->selected == TOTAL_LEVELS) {
    Reset(gs);
  }
}

