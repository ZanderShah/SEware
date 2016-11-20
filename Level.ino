void Reset(GameState *gs) {
  free(gs->words);
  gs->words = NULL;
  free(gs->shapes);
  gs->shapes = NULL;
  gs->needsReset = 1;
}

void SetMemory(GameState *gs, int words, int shapes) {
  gs->numWords = words;
  gs->words = (Word*) malloc(sizeof(Word) * words);
  gs->numShapes = shapes;
  gs->shapes = (Shape*) malloc(sizeof(Shape) * shapes);
}
