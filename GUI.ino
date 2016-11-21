void GUIsetup() {
  OrbitOledInit();
}

void Draw(Shape *pic) {
  for (int i = 0; i < pic->height; i++) {
    for (int j = 0; j < pic->width; j++) {
      if (pic->bmp[i][j]) {
        OrbitOledMoveTo(pic->pos.x + j, pic->pos.y + i);
        OrbitOledDrawPixel();
      }
    }
  }
}

void GUIloop(GameState *gs) {
  OrbitOledClearBuffer();

  for (int i = 0; i < gs->numWords; i++) {
    OrbitOledMoveTo(gs->words[i].x, gs->words[i].y);
    OrbitOledDrawString(gs->words[i].w);
  }

  for (int i = 0; i < gs->numShapes; i++) {
    int x1 = gs->shapes[i].pos.x;
    int width = gs->shapes[i].width;
    int x2 = x1 + width;
    int y1 = gs->shapes[i].pos.y;
    int height = gs->shapes[i].height;
    int y2 = y1 + height;
    
    if (x1 <= 132 && x2 >= 0 && y1 <= 32 && y2 >= 0) {
      OrbitOledMoveTo(x1, y1);
      switch(gs->shapes[i].type) {
        case 1: 
          OrbitOledDrawRect(x2, y2);
          break;
        case 2:
          Draw(&(gs->shapes[i]));
          break;
      }
    }
  }
  
  OrbitOledUpdate();
}

