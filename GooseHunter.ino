void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 1);
    
    strcpy(gs->words[0].w, "~ WEW LAD ~");
    gs->words[0].x = 0;
    gs->words[0].y = 0;

    gs->shapes[0].type = 1;
    gs->shapes[0].x1 = 0;
    gs->shapes[0].y1 = 15;
    gs->shapes[0].x2 = 15;
    gs->shapes[0].y2 = 30;

    gs->needsReset = false;
  }

  gs->shapes[0].x1++;
  gs->shapes[0].x2++;

  if (gs->shapes[0].x1 >= 130) {
    gs->shapes[0].x1 = 0;
    gs->shapes[0].x2 = 15;
  }

  // Checking for party temporarily since party maps to goosehunter
  if (gs->state != GOOSE_HUNTER && gs->state != PARTY) {
    Reset(gs);
  }
}
