#include "./headers/functions.h"

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

const int ARROW_DOWN = 80;
const int ARROW_UP = 72;
const int FIRST_ACTIVE_INDEX = 1;
const char ENTER_KEY = 13;

void showTitleScreen()
{
	FILE* titleFile = fopen("src\\data\\zast.txt", "r"); 
	char symbol;
	while (!feof(titleFile))                        
	{
		fscanf(titleFile, "%c", &symbol);             
		printf("%c", symbol);
	}
	printf("\n");
	fclose(titleFile);
}

int calculateMenuSize(const char* menuItems[])
{
    int index = 0;
	while(menuItems[index] != NULL) {
		index++;
	}
	return index;
}

void drawMenu(const char* menuItems[], int menuSize, int currentMenuItemIndex)
{
	for (int i = 0; i < menuSize; i++)
	{
		if(currentMenuItemIndex == i + 1)
		{
			printf("->");
		} 
		else 
		{
			printf("  ");
		}
		printf("%s", menuItems[i]);
	}	
}

int getUserChoiceFromMenu(const char* menuItems[])
{
	const int MENU_SIZE = calculateMenuSize(menuItems);
	const int LAST_ACTIVE_INDEX = MENU_SIZE;
	int currentMenuItemIndex = FIRST_ACTIVE_INDEX;
	char pressedKey = '1';

	while (pressedKey != 13)
	{
		system("cls");
		drawMenu(menuItems, MENU_SIZE, currentMenuItemIndex);
		pressedKey = _getch();

		switch (pressedKey)
		{
		case ARROW_DOWN: {
			currentMenuItemIndex++;
			if (currentMenuItemIndex == MENU_SIZE + 1)
			{
				currentMenuItemIndex = FIRST_ACTIVE_INDEX;
			}
			break;
		}
		case ARROW_UP: {
			currentMenuItemIndex--;
			if (currentMenuItemIndex == 0)
			{
				currentMenuItemIndex = LAST_ACTIVE_INDEX;
			}
		}
		default:
			break;
		}
	}
	system("cls");
	return currentMenuItemIndex;
}
