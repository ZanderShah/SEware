#ifndef CONSTANTS_H
#define CONSTANTS_H

const int TOTAL_LEVELS = 6;
const int MAIN_MENU = 0;
const int SELECTION = 1;
const int PARTY = 2;
const int GOOSE_HUNTER = 3;
const int SAVAGE_ADMISSIONS = 4;
const int LOCK_PICKER = 5;
const int MATH_PUZZLE=6;
const int GOOSE_JUMPER=6;

const uint32_t SWITCH_COUNT = 2;
const uint32_t SWITCHES[SWITCH_COUNT] = { PA_6, PA_7 };
const uint32_t BUTTON_COUNT = 2;
const uint32_t BUTTONS[BUTTON_COUNT] = { PD_2, PE_0 };
const uint32_t POTENTIOMETER = PE_3;

const int HYPE_THRESHOLD = 1250;
const char *HYPE[] = { "----", "====", "####" };

const char *LEVEL_NAMES[] = { "PARTY MODE", "GOOSE HUNTER", "SAV ADMISSIONS", "LOCK PICKER","MATH PUZZLE", "GOOSE JUMPER" };

const bool BASKET[5][6] = {
  { 0, 0, 1, 1, 1, 1 },
  { 0, 1, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 1, 0 },
  { 1, 1, 1, 1, 0, 0 }
};

const bool LOVE[4][5] = {
  { 0, 1, 0, 1, 0 },
  { 1, 0, 1, 0, 1 }, 
  { 0, 1, 0, 1, 0 },
  { 0, 0, 1, 0, 0 }
};

#endif
