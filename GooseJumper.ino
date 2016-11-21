
int started=0;

bool gooseImg[8][10] = {{0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,1,1},
                        {0,0,0,0,1,0,0,0,1,0},
                        {0,0,1,1,1,1,1,1,1,0},
                        {0,1,1,0,0,0,1,1,0,0},
                        {1,1,1,1,1,1,1,1,0,0},
                        {0,0,1,0,0,0,1,0,0,0},
                        {0,0,1,0,0,0,1,0,0,0},
                      
};

void GooseJumper(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 2);
    
    gs->words[0].x = 0;
    gs->words[0].y = 0;
    strcpy(gs->words[0].w, "GOOSE, JUMP!");

    //the ground
    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 0;
    gs->shapes[0].pos.dX = 0;
    gs->shapes[0].pos.y = 31;
    gs->shapes[0].pos.dY = 31;
    gs->shapes[0].width = 150;
    gs->shapes[0].height = 1;
    gs->shapes[0].visible = true;

    gs->shapes[1].type = 2;
    gs->shapes[1].pos.x = 64;
    gs->shapes[1].pos.dX = 64;
    gs->shapes[1].pos.y = 16;
    gs->shapes[1].pos.dY = 16;
    gs->shapes[1].width = 10;
    gs->shapes[1].height = 8;
    gs->shapes[1].visible = true;

    for (int r =0; r < 8; r++){
      for (int c =0; c <10;c++){
        gs->shapes[1].bmp[r][c] = gooseImg[r][c];
      }
    }
    
    
    
    gs->needsReset = false;
  }

  if (!started){
    
  }

  if (obi->buttons[0] || obi->buttons[1]){//jump
    
  }

  //collision detection:
  

  
  

  
}


