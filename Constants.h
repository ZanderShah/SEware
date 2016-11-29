#ifndef CONSTANTS_H
#define CONSTANTS_H

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 32;
const int MAX_LENGTH = 32;

// Don't want to include Ending in total level count
const int TOTAL_LEVELS = 8;
const int MAIN_MENU = 0;
const int SELECTION = 1;
const int PARTY = 2;
const int GOOSE_HUNTER = 3;
const int COLLECT_LOVE = 4;
const int LOCK_PICKER = 5;
const int GOOSE_JUMPER = 6;
const int GOOSE_FISHER = 7;
const int ENDING = 8;

const int SWITCH_COUNT = 2;
const uint32_t SWITCHES[] = { PA_6, PA_7 };
const int BUTTON_COUNT = 2;
const uint32_t BUTTONS[] = { PD_2, PE_0 };
const int MAX_POTENTIAL = 4390;
const uint32_t POTENTIOMETER = PE_3;
const int LED_COUNT = 5;
const uint32_t LEDS[] = { GREEN_LED, PB_5, PD_6, PC_7, PC_6 };
const float MAXIMUM_READING = 512.0;
const float MAXIMUM_ACCELERATION  = 9.81 * 4.0;
const uint32_t ACCELEROMETER = 0x1D;
const int SHAKE_THRESHOLD = 16;
const size_t DATA_LENGTH = 6;

const int HYPE_THRESHOLD = 1250;
const char HYPE[3][5] = { "----", "====", "####" };

const char LEVEL_NAMES[TOTAL_LEVELS - 1][MAX_LENGTH] = { "INSTRUCTIONS", "PARTY MODE", "GOOSE HUNTER", "COLLECT LOVE", "LOCK PICKER", "GOOSE JUMPER", "GOOSE FISHER"  };
const char GAME_DETAILS[TOTAL_LEVELS - 1][2][MAX_LENGTH] = { {"BTN1 to select", "BTN2 to cycle" }, { "endless partying", "slowly speeds up" }, { "BTNS to shoot", "don't waste ammo" }, { "BTNS to move ^,v", "POT to move <,>" }, {"POT to move <,>", "BTNS to unlock" }, { "BTNS to jump", "dodge everything" }, { "Shake to fish", "careful" } };
const char DIFFICULTY_NAMES[8][3] = { "1A", "1B", "2A", "2B", "3A", "3B", "4A", "4B" };

const int EPS = 35;
const int COOLDOWN = 125;

const int MAX_LOVE = 10;

#endif
