void GUIsetup() {
  OrbitOledInit();
  OrbitOledSetDrawColor(1);
}

void GUIloop(GameState *gs) {
  OrbitOledClearBuffer();

  for (int i = 0; i < gs->numWords; i++) {
    OrbitOledMoveTo(gs->words[i].x, gs->words[i].y);
    OrbitOledDrawString(gs->words[i].w);
  }

  for (int i = 0; i < gs->numShapes; i++) {
    int x1 = gs->shapes[i].pos.x;
    int x2 = gs->shapes[i].pos.x + gs->shapes[i].width;
    int y1 = gs->shapes[i].pos.y;
    int y2 = gs->shapes[i].pos.y + gs->shapes[i].height;
    
    if (x1 <= 132 && x2 >= 0 && y1 <= 32 && y2 >= 0) {
      OrbitOledMoveTo(x1, y1);
      switch(gs->shapes[i].type) {
        case 1: 
          OrbitOledDrawRect(x2, y2);
          break;
      }
    }
  }
  
  OrbitOledUpdate();
}

