#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Constants.h"
#define LED GREEN_LED

typedef struct {
  bool switches[SWITCH_COUNT];
  bool pastButtons[BUTTON_COUNT];
  bool buttons[BUTTON_COUNT];
  float potential;
} OrbitInput;

typedef struct {
  int x;
  int y;
  char w[20];
} Word;

typedef struct {
  int x, y; //curposition 
  double dX, dY; //current position as a double (for accuracy)
  double vX, vY; // velocity in pixels per second. 
  double prevTime;
} Position;

typedef struct {
  int type;
  Position pos;
  int width, height;
  bool visible;
  bool bmp[32][32];
} Shape;

typedef struct {
  int state;
  bool needsReset;
  int selected;

  Word *words;
  int numWords;

  Shape *shapes;
  int numShapes;

  int score;
} GameState;

OrbitInput obi;
GameState gs;

void (*level[TOTAL_LEVELS]) (OrbitInput *obi, GameState *gs);

void setup() {
  pinMode(LED, OUTPUT); 
  UIsetup();
  GUIsetup();
  
  gs.state = MAIN_MENU;
  gs.needsReset = true;
  
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = GooseHunter;
  level[3] = GooseHunter;
  level[4] = SavageAdmissions;
  level[5] = LockPicker;
  level[6] = MathPuzzle;
  level[7] = GooseJumper;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);
}
