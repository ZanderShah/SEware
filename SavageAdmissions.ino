Shape CreateShape() {
  Shape ret;
  ret.type = 1;
  ret.pos.x = -rand() % 100;
  ret.pos.dX = ret.pos.x;
  ret.pos.y = rand() % 26;
  ret.pos.dY = ret.pos.y;
  ret.width = 3;
  ret.height = 3;
  ret.pos.vX = 30;
  ret.pos.vY = 0;
  ret.pos.prevTime = millis();
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

    gs->shapes[1].type = 2;
    gs->shapes[1].pos.x = 115;
    gs->shapes[1].pos.dX = 115;
    gs->shapes[1].pos.y = 10;
    gs->shapes[1].pos.dY = 10;
    gs->shapes[1].width = 2;
    gs->shapes[1].height = 8;
    gs->shapes[1].pos.vX = 0;
    gs->shapes[1].pos.vY = 0;
    gs->shapes[1].pos.prevTime = millis();

    for (int i = 2; i < gs->numShapes; i++) {
      gs->shapes[i] = CreateShape();
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
      gs->shapes[i] = CreateShape();
    }
    if (gs->shapes[i].pos.x > 130) {
      gs->shapes[i] = CreateShape();
    }
  }

  for (int i = 1; i < gs->numShapes; i++) {
    UpdatePosition(&(gs->shapes[i].pos));
  }

  sprintf(gs->words[0].w, "%d", gs->score);

  if (gs->score == 101) {
    gs->state = SELECTION;
  }
  if (gs->state != SAVAGE_ADMISSIONS) {
    Reset(gs);
  }
}
