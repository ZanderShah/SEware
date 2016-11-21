Shape CreateLove() {
  Shape ret;
  ret.type = 2;
  ret.pos.x = -rand() % 100;
  ret.pos.dX = ret.pos.x;
  ret.pos.y = rand() % 26;
  ret.pos.dY = ret.pos.y;
  ret.width = 5;
  ret.height = 4;
  ret.pos.vX = 30;
  ret.pos.vY = 0;
  for (int i = 0; i < ret.height; i++) {
    for (int j = 0; j < ret.width; j++) {
      ret.bmp[i][j] = LOVE[i][j];
    }
  }
  ret.pos.prevTime = millis();
  ret.visible = true;
  return ret;
}

bool intersect(Shape i, Shape j) {
  return abs(i.pos.x + i.width / 2 - j.pos.x - j.width / 2) <= i.width && abs(i.pos.y + i.height / 2 - j.pos.y - j.height / 2) <= i.height / 2;
}

void SavageAdmissions(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 10);
    gs->score = 0;

    gs->words[0].x = 0;
    gs->words[0].y = 0;
   
    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 120;
    gs->shapes[0].pos.dX = 120;
    gs->shapes[0].pos.y = 0;
    gs->shapes[0].pos.dY = 0;
    gs->shapes[0].width = 0;
    gs->shapes[0].height = 32;
    gs->shapes[0].visible = true;

    gs->shapes[1].type = 2;
    gs->shapes[1].pos.x = 115;
    gs->shapes[1].pos.dX = 115;
    gs->shapes[1].pos.y = 10;
    gs->shapes[1].pos.dY = 10;
    gs->shapes[1].width = 6;
    gs->shapes[1].height = 5;
    gs->shapes[1].pos.vX = 0;
    gs->shapes[1].pos.vY = 0;
    gs->shapes[1].pos.prevTime = millis();
    gs->shapes[1].visible = true;
    
    for (int i = 0; i < gs->shapes[1].height; i++) {
      for (int j = 0; j < gs->shapes[1].width; j++) {
        gs->shapes[1].bmp[j][i] = BASKET[i][j];
      }
    }

    for (int i = 2; i < gs->numShapes; i++) {
      gs->shapes[i] = CreateLove();
    }

    gs->needsReset = false;
  }

  if (obi->buttons[0] ^ obi->buttons[1] == 0) {
    gs->shapes[1].pos.vY = 0;
  } else if (obi->buttons[0] && gs->shapes[1].pos.y < 25) {
    gs->shapes[1].pos.vY = 30;
  } else if (obi->buttons[1] && gs->shapes[1].pos.y > 0) {
    gs->shapes[1].pos.vY = -30;
  } else {
    gs->shapes[1].pos.vY = 0;
  }

  for (int i = 2; i < gs->numShapes; i++) {
    if (intersect(gs->shapes[1], gs->shapes[i])) {
      gs->score++;
      gs->shapes[i] = CreateLove();
    }
    if (gs->shapes[i].pos.x > 130) {
      gs->shapes[i] = CreateLove();
    }
  }

  for (int i = 1; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  sprintf(gs->words[0].w, "%d", gs->score);

  if (gs->score == 5) {
    gs->state = SELECTION;
  }
  if (gs->state != SAVAGE_ADMISSIONS) {
    Reset(gs);
  }
}
