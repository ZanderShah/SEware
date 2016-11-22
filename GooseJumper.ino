
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


void GooseJumper(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 4);

    gs->words[0] = { 0, 0, true };
    strcpy(gs->words[0].w, "GOOSE, JUMP!");
    
    // Ground
    gs->shapes[0] = { 1, { 0, 31, 0, 31, 0, 0, millis() }, 150, 1, true };
    // Goose
    gs->shapes[1] = { 2, { 64, 22, 64, 22, 0, 0, millis() }, 10, 8, true };
    
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 10; c++) {
        gs->shapes[1].bmp[r][c] = gooseImg[r][c];
      }
    }

    // Goose Poop
    gs->shapes[2] = { 2, { 100, 22, 100, 22, 0, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <8; c++) {
        gs->shapes[2].bmp[r][c] = poopImg[r][c];
      }
    }
  
    // Player
    gs->shapes[3] = { 2, { 50, 22, 50, 22, 0, 0, millis() }, 8, 8, true };
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c <8; c++) {
        gs->shapes[3].bmp[r][c] = playerImage[r][c];
      }
    }
    
    gs->needsReset = false;
  }

  if (!started){
    
  }

  if (obi->buttons[0] || obi->buttons[1]){//jump
    
  }

  //collision detection:
  

  if (gs->state != GOOSE_JUMPER) {
    Reset(gs);
  }
}


