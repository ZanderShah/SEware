void Sync(OrbitInput *obi, GameState *gs) {
  for (int i = 0; i < BUTTON_COUNT; i++) {
    if (obi->buttons[i] && gs->buttonCooldown[i] == 0)
      gs->buttonCooldown[i] = COOLDOWN;
    if (gs->buttonCooldown[i])
      gs->buttonCooldown[i]--;
  }
}

void MainMenu(OrbitInput *obi, GameState *gs) {
  if (gs->words == NULL) {
    gs->words = (Word*) malloc(sizeof(Word) * 4);
    gs->n = 3;

    strcpy(gs->words[0].w, "~SEXXIWARE~");
    gs->words[0].x = 20;
    gs->words[0].y = 0;

    strcpy(gs->words[1].w, ">>TURN UP<<");
    gs->words[1].x = 20;
    gs->words[1].y = 10;

    gs->words[2].x = 5;
    gs->words[2].y = 20;
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
    free(gs->words);
    gs->words = NULL;
  }
}

void Selection(OrbitInput *obi, GameState *gs) {
  if (gs->words == NULL) {
    gs->words = (Word*) malloc(sizeof(Word) * 2);
    gs->n = 2;

    strcpy(gs->words[0].w, "GAME SELECTION");
    gs->words[0].x = 0;
    gs->words[0].y = 0;
    
    gs->words[1].x = 0;
    gs->words[1].y = 10;
  }

  strcpy(gs->words[1].w, LEVEL_NAMES[gs->selected]);

  if (obi->buttons[0] && gs->buttonCooldown[0] == 0) {
    gs->state = gs->selected + 2;
  } 
  if (obi->buttons[1] && gs->buttonCooldown[1] == 0) {
    gs->selected = (gs->selected + 1) % (sizeof(LEVEL_NAMES) / sizeof(LEVEL_NAMES[0]));
  }
    
  if (gs->state != SELECTION) {
    free(gs->words);
    gs->words = NULL;
  }
}

void TestGame(OrbitInput *obi, GameState *gs) {
  if (gs->words == NULL) {
    gs->words = (Word*) malloc(sizeof(Word));
    gs->n = 1;

    strcpy(gs->words[0].w, "WOW, WHAT FUN!");
    gs->words[0].x = 0;
    gs->words[0].y = 1;
  }
}

void Level1(OrbitInput *obi, GameState *gs){
  
}


typedef struct{
  int x,y; //curposition 
  double dX,dY; //current position as a double (for accuracy)
  double vX,vY; // velocity in pixels per second. 
  double prevTime;
}Position;

void UpdatePosition(Position *p){
  if (!p){
    return;
  }
  double elapsedTime = millis()-p->prevTime;
  
  p->dX += (elapsedTime/1000.0) * vX;
  p->dY+=(elapsedTime/1000.0) *vY;

  p->x = (int)dX;
  p->y = (int)dY;
  
  p->prevTime =millis();
}







