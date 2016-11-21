double epsilon = 35;
double solution[] = { 0,0,0 };
int initialized = 0;
int curSolution = 0;

void LockPicker(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 1);
    
    gs->words[0].x = 0;
    gs->words[0].y = 0;
    gs->words[1].x = 0;
    gs->words[1].y = 20;
    strcpy(gs->words[0].w, "|");
    
    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 0;
    gs->shapes[0].pos.dX = 0;
    gs->shapes[0].pos.y = 20;
    gs->shapes[0].pos.dY = 20;
    gs->shapes[0].width = 128;
    gs->shapes[0].height = 1;

    gs->needsReset = false;
  }
  
  if (!initialized){//set the solution!
    initialized = 1;
    srand((time_t) millis());
    for (int i = 0; i < 3 ;i++){
      solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      while (i > 0 && fabs(solution[i]-solution[i - 1]) < 500){
        solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      }
    }

    strcpy(gs->words[0].w, "Pick a lock!");
    gs->words[0].x = 0;
    gs->words[0].y = 0;

  }
  

  double curVal = (double) obi->potential;
  gs->words[1].x = (int) ((curVal/4096.0) * 32);
  if (fabs(curVal - solution[curSolution]) <epsilon ){
    digitalWrite(LED, HIGH);
    strcpy(gs->words[0].w, "O");
    if (obi->buttons[0] || obi->buttons[1]){
      curSolution ++;
    }
  }else{
    digitalWrite(LED, LOW);
    strcpy(gs->words[0].w, "|");
  }

  if (curSolution >=3){//win
    
  }

  
}


