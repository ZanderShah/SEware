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
    OrbitOledMoveTo(gs->shapes[i].x1, gs->shapes[i].y1);
    switch(gs->shapes[i].type) {
      case 1: 
        OrbitOledDrawRect(gs->shapes[i].x2, gs->shapes[i].y2);
        break;
    }
  }
  
  OrbitOledUpdate();
}

