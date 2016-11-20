#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <string.h>
<<<<<<< HEAD
=======
#include <math.h>
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849
#include "Constants.h"

typedef struct {
  bool switches[2];
<<<<<<< HEAD
  bool pastButtons[2];
=======
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849
  bool buttons[2];
  float potential;
} OrbitInput;

typedef struct {
  int x;
  int y;
  char w[20];
} Word;

typedef struct {
<<<<<<< HEAD
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
=======
  int state;

  int buttonCooldown[2];
  
  Word *words;
  int n;
  
  int selected;
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849
} GameState;

OrbitInput obi;
GameState gs;

<<<<<<< HEAD
void (*level[4]) (OrbitInput *obi, GameState *gs);
=======
void (*level[5]) (OrbitInput *obi, GameState *gs);
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849

void setup() {
  UIsetup();
  GUIsetup();
<<<<<<< HEAD

  gs.state = MAIN_MENU;
  gs.needsReset = true;
  
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = GooseHunter;
  level[3] = GooseHunter;
=======
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = TestGame;
  level[3] = TestGame;
  level[4] = TestGame;
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);
<<<<<<< HEAD
=======
  
  Sync(&obi, &gs);
>>>>>>> 09c42cad74df9c4a99d9b354b4664b8574d44849

  delay(33.33);
}
