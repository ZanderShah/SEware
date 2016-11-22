bool master[SCREEN_HEIGHT + 1][SCREEN_WIDTH + 1];

void GUIsetup() {
  OrbitOledInit();
}

void Draw(Shape *pic) {
  for (int i = 0; i < pic->height; i++) {
    for (int j = 0; j < pic->width; j++) {
      if (pic->pos.y + i >= 0 && pic->pos.y + i <= SCREEN_HEIGHT
        && pic->pos.x + j >= 0 && pic->pos.x + j <= SCREEN_WIDTH)
        master[pic->pos.y + i][pic->pos.x + j] |= pic->bmp[i][j];
    }
  }
}

void GUIloop(GameState *gs) {
  OrbitOledClearBuffer();

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      master[i][j] = 0;
    }
  }
  
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
    
    if (gs->shapes[i].visible) {
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
  }

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      if (master[i][j]) {
        OrbitOledMoveTo(j, i);
        OrbitOledDrawPixel();
      }
    }
  }
  
  OrbitOledUpdate();
}


