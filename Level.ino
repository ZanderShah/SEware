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
  gs->needsReset = true;
}

void UpdatePosition(Position *p) {
  if (!p) {
    return;
  }
  double elapsedTime = millis() - p->prevTime;
  
  p->dX += (elapsedTime / 1000.0) * p->vX;
  p->dY += (elapsedTime / 1000.0) * p->vY;

  p->x = (int) p->dX;
  p->y = (int) p->dY;
  
  p->prevTime = millis();
}







