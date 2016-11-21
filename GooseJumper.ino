
Position playerPos;
int started=0;

void GooseJumper(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 2, 2);
    
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
    
    
    gs->needsReset = false;
  }

  if (!started){
    playerPos.x=48;
    playerPos.dX=playerPos.x;
    playerPos.y=25;
    playerPos.dY=playerPos.y;
    playerPos.vX=0;
    playerPos.vY=0;
    started=1;
  }

  if (obi->buttons[0] || obi->buttons[1]){//jump
    
  }

  //collision detection:
  

  
  

  
}


