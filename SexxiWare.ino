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
#include "Pictures.h"

typedef struct {
  bool switches[SWITCH_COUNT];
  bool pastButtons[BUTTON_COUNT];
  bool buttons[BUTTON_COUNT];
  float potential;
} OrbitInput;

typedef struct {
  int x, y;
  bool visible;
  char w[20];
} Word;

typedef struct {
  int x, y;
  double dX, dY;
  double vX, vY;
  double prevTime;
  double aY, aX;
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
  int selected;
  int numWords;
  Word *words;
  int numShapes;
  Shape *shapes;
  int score;
  int lives; 
  bool needsReset;
} GameState;

OrbitInput obi;
GameState gs;

void (*level[TOTAL_LEVELS]) (OrbitInput *obi, GameState *gs);

void setup() {
  UIsetup();
  GUIsetup();
  
  gs.state = MAIN_MENU;
  gs.needsReset = true;

  srand((time_t) millis());
  
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = Party;
  level[3] = GooseHunter;
  level[4] = CollectLove;
  level[5] = LockPicker;
  level[6] = GooseJumper;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);
}
