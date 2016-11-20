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
  bool buttons[2];
  float potential;
} OrbitInput;

typedef struct {
  int x;
  int y;
  char w[20];
} Word;

typedef struct {
  int state;

  int buttonCooldown[2];
  
  Word *words;
  int n;
  
  int selected;
} GameState;

OrbitInput obi;
GameState gs;

void (*level[5]) (OrbitInput *obi, GameState *gs);

void setup() {
  UIsetup();
  GUIsetup();
  level[0] = MainMenu;
  level[1] = Selection;
  level[2] = TestGame;
  level[3] = TestGame;
  level[4] = TestGame;
}

void loop() {
  UIloop(&obi);
  
  (*level[gs.state])(&obi, &gs);
  
  GUIloop(&gs);
  
  Sync(&obi, &gs);

  delay(33.33);
}
