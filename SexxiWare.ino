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
  double dX, dY;
  double vX, vY;
  double prevTime;
  double aY, aX;
  bool frozen;
} Position;

typedef struct {
  Position pos;
  bool visible;
  char w[MAX_LENGTH];
} Word;

typedef struct {
  int type;
  Position pos;
  int width, height;  
  bool visible; 
  bool bmp[MAX_LENGTH][MAX_LENGTH];
} Shape;

typedef struct {
  int state;
  int selected;

  bool needsReset, partyReset;
  int difficultySelected;

  int score;
  int lives; 
  int streak;
  bool win;
  
  int numWords;
  Word *words;
  
  int numShapes;
  Shape *shapes;
} GameState;

OrbitInput obi;
GameState gs;

void (*level[TOTAL_LEVELS + 1]) (OrbitInput *obi, GameState *gs);
int collectNoise = 1;

void setup() {
  UIsetup();
  GUIsetup();
  
  gs.state = MAIN_MENU;
  gs.needsReset = true;
  gs.partyReset = true;
  
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = Party;
  level[3] = GooseHunter;
  level[4] = CollectLove;
  level[5] = LockPicker;
  level[6] = GooseJumper;
  level[7] = GooseFisher;
  level[8] = Ending;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);
}
