Shape CreateShape() {
  Shape ret;
  ret.type = 1;
  ret.pos.x = -rand() % 100;
  ret.pos.dX = ret.pos.x;
  ret.pos.y = rand() % 30;
  ret.pos.dY = ret.pos.y;
  ret.width = 2;
  ret.height = 5;
  ret.pos.vX = 30;
  ret.pos.vY = 0;
  ret.pos.prevTime = millis();
  return ret;
}

void SavageAdmissions(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 1, 10);
    gs->score = 0;

    gs->words[0].x = 0;
    gs->words[0].y = 0;
   
    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 100;
    gs->shapes[0].pos.dX = 100;
    gs->shapes[0].pos.y = 0;
    gs->shapes[0].pos.dY = 0;
    gs->shapes[0].width = 0;
    gs->shapes[0].height = 32;

    gs->shapes[1].type = 1;
    gs->shapes[1].pos.x = 98;
    gs->shapes[1].pos.dX = 98;
    gs->shapes[1].pos.y = 0;
    gs->shapes[1].pos.dY = 0;
    gs->shapes[1].width = 0;
    gs->shapes[1].height = 8;
    gs->shapes[1].pos.vX = 0;

    for (int i = 2; i < gs->numShapes; i++) {
      gs->shapes[i] = CreateShape();
    }

    gs->needsReset = false;
  }

  if (obi->buttons[0] && gs->shapes[1].pos.y <132) {
    gs->shapes[1].pos.vY = 20;
  } else if (obi->buttons[1] && gs->shapes[1].pos.y >0) {
    gs->shapes[1].pos.vY = -20;
  } else {
    gs->shapes[1].pos.vY = 0;
  }

  for (int i = 2; i < gs->numShapes; i++) {
    if (gs->shapes[1].pos.x - gs->shapes[i].pos.x <= EPS 
    && abs(gs->shapes[1].pos.y - gs->shapes[i].pos.y) <= EPS) {
      gs->score++;
      gs->shapes[i] = CreateShape();
    }
    if (gs->shapes[i].pos.x > 100) {
      gs->shapes[i] = CreateShape();
    }
  }

  for (int i = 1; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  sprintf(gs->words[0].w, "%d", gs->score);

  if (gs->state != SAVAGE_ADMISSIONS) {
    Reset(gs);
  }
}
