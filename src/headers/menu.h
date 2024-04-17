#ifndef MENU_H
#define MENU_H

#define FIRST_ACTIVE_INDEX 1
#define ARROW_DOWN 80
#define ARROW_UP 72
#define ENTER_KEY 13

#define CONSOLE_INPUT_CASE 1
#define FILE_INPUT_CASE 2
#define SAVE_INPUT_CASE 3
#define CALCULATE_DATA_CASE 4
#define EXPORT_CALCULATION_CASE 5
#define CALCULATE_WITH_ACCURACY_CASE 6
#define EXIT_CASE 7

void showTitleScreen();
int getUserChoiceFromMenu();

#endif