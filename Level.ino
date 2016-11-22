void SetMemory(GameState *gs, int words, int shapes) {
  gs->numWords = words;
  gs->words = (Word*) malloc(sizeof(Word) * gs->numWords);
  gs->numShapes = shapes;
  gs->shapes = (Shape*) malloc(sizeof(Shape) * gs->numShapes);
}

void Reset(GameState *gs) {
  free(gs->words);
  gs->words = NULL;
  
  free(gs->shapes);
  gs->shapes = NULL;

  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LEDS[i], LOW);
  }

  gs->needsReset = true;
}

void UpdatePosition(Position *p) {
  if (!p) {
    return;
  }
  
  double elapsedTime = millis() - p->prevTime;
  double temp = (elapsedTime / 1000.0);
  p->dX += temp * p->vX;
  p->dY += temp * p->vY;

  p->vX += temp * p->aX;
  p->vY += temp * p->aY;
  
  p->x = (int) (p->dX +1);
  p->y = (int) (p->dY +1);
  
  p->prevTime = millis();
}

bool intersect(Shape i, Shape j) {
  return abs(i.pos.x + i.width / 2 - j.pos.x - j.width / 2) <= i.width / 2
    && abs(i.pos.y + i.height / 2 - j.pos.y - j.height / 2) <= i.height / 2;
}







