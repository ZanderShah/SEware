double epsilon = 35;
double solution[] = { 0,0,0 };
int initialized = 0;
int curSolution = 0;

void LockPicker(OrbitInput *obi, GameState *gs) {
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
  
  if (!initialized){//set the solution!
    initialized = 1;
    //srand(time(NULL));
    for (int i = 0; i < 3 ;i++){
      solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      while (i > 0 && fabs(solution[i]-solution[i - 1]) < 500){
        solution[i] = (rand() % (4000 + 1 - 100)) + 100;
      }
    }

    strcpy(gs->words[0].w, "Pick a lock");
    gs->words[0].x = 0;
    gs->words[0].y = 0;

  }
  

  double curVal = (double) obi->potential;

  if (fabs(curVal - solution[curSolution]) <epsilon ){
    digitalWrite(LED, HIGH);
    if (obi->buttons[0]){
      curSolution ++;
    }
  }else{
    digitalWrite(LED, LOW);

  }

  if (curSolution >=3){//win
    
  }

  
}


