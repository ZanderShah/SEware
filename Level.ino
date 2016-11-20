void Reset(GameState *gs) {
  free(gs->words);
  gs->words = NULL;
  free(gs->shapes);
  gs->shapes = NULL;
  gs->needsReset = 1;
}

void SetMemory(GameState *gs, int words, int shapes) {
  gs->numWords = words;
  gs->words = (Word*) malloc(sizeof(Word) * words);
  gs->numShapes = shapes;
  gs->shapes = (Shape*) malloc(sizeof(Shape) * shapes);
}

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
    Reset(gs);
  } 
}

void TestGraphics(OrbitInput *obi, GameState *gs) {
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
}

void TestGame(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 0);
    
    strcpy(gs->words[0].w, "WOW, WHAT FUN!");
    gs->words[0].x = 0;
    gs->words[0].y = 0;

    gs->needsReset = false;
  }
}

void Level1(OrbitInput *obi, GameState *gs){
  
}

