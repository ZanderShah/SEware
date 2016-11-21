Shape CreateShape() {
  Shape ret;
  ret.type = 1;
  ret.pos.x = - 10;
  ret.pos.dX = ret.pos.x;
  ret.pos.y = 10;
  ret.pos.dY = ret.pos.y;
  ret.width = 15;
  ret.height = 15;
  ret.pos.vX = rand() % 30 + 10;
  ret.pos.vY=0;
  ret.pos.prevTime=millis();
  return ret;
}

void SavageAdmissions(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 5);
   
    gs->shapes[0].type = 1;
    gs->shapes[0].pos.x = 100;
    gs->shapes[0].pos.dX = 100;
    gs->shapes[0].pos.y = 0;
    gs->shapes[0].pos.dY = 0;
    gs->shapes[0].width = 0;
    gs->shapes[0].height = 32;

    for (int i = 1; i < gs->numShapes; i++) {
      gs->shapes[i].type = 1;
      gs->shapes[i].pos.x = 101;
    }

    gs->needsReset = false;
  }

  for (int i = 1; i < gs->numShapes; i++)
    if (gs->shapes[i].pos.x > 100) {
      gs->shapes[i] = CreateShape();
    }

  for (int i = 1; i < gs->numShapes; i++)
    if (gs->shapes[i].pos.x <= 100) {
      UpdatePosition(&(gs->shapes[i].pos));
    }

  if (gs->state != SAVAGE_ADMISSIONS) {
    Reset(gs);
  }
}
