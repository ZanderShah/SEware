void GUIsetup() {
  OrbitOledInit();
}

void Draw(Shape *pic) {
  for (int i = 0; i < pic->height; i++) {
    for (int j = 0; j < pic->width; j++) {
        OrbitOledMoveTo(pic->pos.x + j, pic->pos.y + i);
        OrbitOledSetDrawColor(pic->bmp[i][j]);
        OrbitOledDrawPixel();
    }
  }
}

void GUIloop(GameState *gs) {
  OrbitOledClearBuffer();

  for (int i = 0; i < gs->numWords; i++) {
    if (gs->words[i].visible) {
      OrbitOledMoveTo(gs->words[i].x, gs->words[i].y);
      OrbitOledDrawString(gs->words[i].w);
    }
  }

  for (int i = 0; i < gs->numShapes; i++) {
    int x1 = gs->shapes[i].pos.x;
    int x2 = x1 + gs->shapes[i].width;
    int y1 = gs->shapes[i].pos.y;
    int y2 = y1 + gs->shapes[i].height;
    
    if (gs->shapes[i].visible && x1 <= SCREEN_WIDTH && x2 >= 0 
      && y1 <= SCREEN_HEIGHT && y2 >= 0) {
      switch(gs->shapes[i].type) {
        case 1: 
          OrbitOledSetDrawColor(1);
          OrbitOledMoveTo(x1, y1);
          OrbitOledDrawRect(x2, y2);
          break;
        case 2:
          Draw(&(gs->shapes[i]));
          break;
      }
    }

    UpdatePosition(&(gs->shapes[i].pos));
  }
  
  OrbitOledUpdate();
}

