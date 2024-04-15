#ifndef INTERFACE_H
#define INTERFACE_H

#define FIRST_ACTIVE_INDEX 1
#define ARROW_DOWN 80
#define ARROW_UP 72
#define ENTER_KEY 13

#ifdef _WIN32
#include <conio.h>
#else
//
#endif

void clearConsole();
void showTitleScreen();
int getUserChoiceFromMenu(const char* menuItems[]);
#endif