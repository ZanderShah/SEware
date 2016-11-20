#ifndef CONSTANTS_H
#define CONSTANTS_H

const int TOTAL_LEVELS = 5;
const int MAIN_MENU = 0;
const int SELECTION = 1;
const int PARTY = 2;
const int GOOSE_HUNTER = 3;
const int SAVAGE_ADMISSIONS = 4;

const uint32_t SWITCH_COUNT = 2;
const uint32_t SWITCHES[SWITCH_COUNT] = { PA_6, PA_7 };
const uint32_t BUTTON_COUNT = 2;
const uint32_t BUTTONS[BUTTON_COUNT] = { PD_2, PE_0 };
const uint32_t POTENTIOMETER = PE_3;

const int HYPE_THRESHOLD = 1250;
const char *HYPE[] = { "----", "====", "####" };

const char *LEVEL_NAMES[] = { "PARTY MODE", "GOOSE HUNTER", "SAV ADMISSIONS" };

#endif
