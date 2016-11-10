#ifndef SNAKEFUNCTIONS_H
#define SNAKEFUNCTIONS_H
char chararray[31][103];

char holder;

int holdery[100];
int holderx[102];

int appley;
int applex;

void drawTitleSrn();
void printCharArray(int LevelNum, int snakelength);
void borderCharArray();
void PrintLevel(int LevelNum, bool newLevel);
void ClearScreen();
void init_curses();
void checkArray();
void newApple();
void clearCharArray();
void LevelTwo();
#endif