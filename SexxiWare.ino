#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <string.h>
#include <math.h>
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

typedef struct {
  int x, y; //curposition 
  double dX, dY; //current position as a double (for accuracy)
  double vX, vY; // velocity in pixels per second. 
  double prevTime;
} Position;

OrbitInput obi;
GameState gs;

void (*level[4]) (OrbitInput *obi, GameState *gs);

void setup() {
  UIsetup();
  GUIsetup();
  
  gs.state = MAIN_MENU;
  gs.needsReset = true;
  
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = GooseHunter;
  level[3] = GooseHunter;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);

  delay(33.33);
}
