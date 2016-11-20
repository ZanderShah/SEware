Shape CreateShape() {
  Shape ret;
  ret.type = 1;
  ret.x1 = - rand() % 100;
  ret.y1 = rand() % 15;
  ret.x2 = ret.x1 + 15;
  ret.y2 = ret.y1 + 15;
  return ret;
}



void SavageAdmissions(OrbitInput *obi, GameState *gs) {
  if (gs->needsReset) {
    SetMemory(gs, 0, 5);
   
    gs->shapes[0].type = 1;
    gs->shapes[0].x1 = 100;
    gs->shapes[0].y1 = 0;
    gs->shapes[0].x2 = 100;
    gs->shapes[0].y2 = 32;

    for (int i = 1; i < gs->numShapes; i++) {
      gs->shapes[i].type = 1;
      gs->shapes[i].x1 = 101;
    }

    gs->needsReset = false;
  }

  for (int i = 1; i < gs->numShapes; i++)
    if (gs->shapes[i].x1 > 100) {
      gs->shapes[i] = CreateShape();
    }

  for (int i = 1; i < gs->numShapes; i++)
    if (gs->shapes[i].x1 <= 100) {
      gs->shapes[i].x1++;
      gs->shapes[i].x2++;
    }

  if (gs->state != SAVAGE_ADMISSIONS) {
    Reset(gs);
  }
}
