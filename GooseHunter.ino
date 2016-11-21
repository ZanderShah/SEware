void GooseHunter(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 1);
    
    strcpy(gs->words[0].w, "~ WEW LAD ~");
    gs->words[0].x = 0;
    gs->words[0].y = 0;

    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 0;
    gs->shapes[0].pos.dX = 0;
    gs->shapes[0].pos.y = 15;
    gs->shapes[0].pos.dY = 15;
    gs->shapes[0].width = 15;
    gs->shapes[0].height = 15;

    gs->needsReset = false;
  }

  gs->shapes[0].pos.x++;

  if (gs->shapes[0].pos.x >= 130) {
    gs->shapes[0].pos.x = 0;
    gs->shapes[0].pos.dX = 0;
  }

  // Checking for party temporarily since party maps to goosehunter
  if (gs->state != GOOSE_HUNTER && gs->state != PARTY) {
    Reset(gs);
  }
}
