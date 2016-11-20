#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <string.h>
#include "Constants.h"

typedef struct {
  bool switches[2];
  bool pastButtons[2];
  bool buttons[2];
  float potential;
} OrbitInput;

typedef struct {
  int x;
  int y;
  char w[20];
} Word;

typedef struct {
  int type;
  int x1;
  int y1;
  int x2;
  int y2;
  char *bmp;
} Shape;

typedef struct {
  int state;
  bool needsReset;
  int selected;

  Word *words;
  int numWords;

  Shape *shapes;
  int numShapes;
} GameState;

OrbitInput obi;
GameState gs;

void (*level[9]) (OrbitInput *obi, GameState *gs);

void setup() {
  UIsetup();
  GUIsetup();
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = TestGraphics;
  level[3] = TestGame;
  level[4] = TestGame;
  level[5] = TestGame;
  level[6] = TestGame;
  level[7] = TestGame;
  level[8] = TestGame;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);

  delay(33.33);
}
