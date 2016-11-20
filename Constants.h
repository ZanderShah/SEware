#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MAIN_MENU = 0;
const int SELECTION = 1;
const int TEST_GAME = 2;

const uint32_t SWITCH_COUNT = 2;
const uint32_t SWITCHES[SWITCH_COUNT] = { PA_6, PA_7 };
const uint32_t BUTTON_COUNT = 2;
const uint32_t BUTTONS[BUTTON_COUNT] = { PD_2, PE_0 };
const uint32_t POTENTIOMETER = PE_3;

const int HYPE_THRESHOLD = 1250;
const char *HYPE[] = { "----", "====", "####" };

const char *LEVEL_NAMES[] = { "PARTY MODE", "GAME 1",  "GAME 2", "GAME 3", "GAME 4", "GAME 5", "GAME 6" };

const int COOLDOWN = 175;

const int CROSS = 2;

#endif
