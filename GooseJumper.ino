
int started=0;

bool gooseImg[8][10] = {{0,0,0,0,0,0,0,0,1,1},
                        {0,0,0,0,0,0,0,0,1,0},
                        {0,0,0,0,0,0,0,0,1,0},
                        {0,0,1,1,1,1,1,1,1,0},
                        {0,1,1,0,0,0,1,1,0,0},
                        {1,1,1,1,1,1,1,1,0,0},
                        {0,0,1,0,0,0,1,0,0,0},
                        {0,0,1,0,0,0,1,0,0,0},
                      
};

bool poopImg[8][8] =  { {0,0,0,0,0,0,0,0},
                        {0,0,0,1,1,0,0,0},
                        {0,0,0,1,1,0,0,0},
                        {0,0,1,0,1,1,0,0},
                        {0,0,1,1,1,1,1,0},
                        {0,0,1,0,0,1,1,0},
                        {0,0,1,0,1,1,1,0},
                        {1,1,1,1,1,1,1,1},
                      
};


bool playerImage[8][8]={{0,0,1,1,1,1,0,0},
                        {0,0,1,0,0,1,0,0},
                        {0,0,1,0,0,1,0,0},
                        {0,0,0,1,0,0,0,0},
                        {0,1,1,1,1,1,0,0},
                        {0,0,0,1,0,0,0,0},
                        {0,0,1,0,1,0,0,0},
                        {0,0,1,0,1,0,0,0},
                      
};

Shape CreateJumpObject(){
  int tx= rand() %50+130;
  Shape ret= { 2, { tx, 22, tx, 22, -20, 0, millis() }, 10, 8, true };
  int retWidth,retHeight;
  
  if (rand() %2==1){ //goose!
    ret.width=10;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <10; c++) {
        ret.bmp[r][c] = gooseImg[r][c];
      }
    }
  }else{ //poop
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <8; c++) {
        ret.bmp[r][c] = poopImg[r][c];
      }
    }
  }
  return ret;
  
  
}

int levelLength=1000;

void GooseJumper(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 6);

//    gs->words[0] = { 0, 0, true };
//    strcpy(gs->words[0].w, "GOOSE, JUMP!");
    
    // Ground
    gs->shapes[0] = { 1, { 0, 31, 0, 31, 0, 0, millis() }, 150, 3, true };
    // Goose
    gs->shapes[1] = { 2, { 150, 22, 150, 22, -20, 0, millis() }, 10, 8, true };
    
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 10; c++) {
        gs->shapes[1].bmp[r][c] = gooseImg[r][c];
      }
    }

    // Goose Poop
    gs->shapes[2] = { 2, { 225, 22, 225, 22, -20, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <8; c++) {
        gs->shapes[2].bmp[r][c] = poopImg[r][c];
      }
    }
  
    // Player
    gs->shapes[3] = { 2, { 48, 22, 48, 22, 0, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <8; c++) {
        gs->shapes[3].bmp[r][c] = playerImage[r][c];
      }
    }

    //finish bar
    gs->shapes[4] = { 2, { levelLength, 22, levelLength, 22, -20, 0, millis() }, 100, 20, false };

    //progress bar
    gs->shapes[5] = { 1, { 0, 0, 0, 0, 0, 0, millis() }, 0, 2, true };
    gs->needsReset = false;
    
  }

  if (!started){
    
  }

  if ((obi->buttons[0] || obi->buttons[1]) && fabs(gs->shapes[3].pos.aY) <0.01){//jump
    gs->shapes[3].pos.aY=60;
    gs->shapes[3].pos.vY=-40;
  }

  if (gs->shapes[3].pos.y >=24){
    gs->shapes[3].pos.y=22;
    gs->shapes[3].pos.dY=22;
    gs->shapes[3].pos.aY=0;
    gs->shapes[3].pos.vY=0;
  }


  //update obstacles
  for (int i =1; i <=2; i++){
    if (gs->shapes[i].pos.x <-10){
      gs->shapes[i] = CreateJumpObject();
    }
  }

  //collision detection:
  for (int i =1; i <=2; i++){
    if (intersect(gs->shapes[i], gs->shapes[3])){
      gs->state=MAIN_MENU;
    }
  }

  //update progress bar:
  gs->shapes[5].width = (int) ((levelLength-gs->shapes[4].pos.dX) /levelLength *128.0);

  //check win
  if (gs->shapes[5].width >=128){
    gs->state=MAIN_MENU;
  }

  
  if (gs->state != GOOSE_JUMPER) {
    Reset(gs);
  }
}


