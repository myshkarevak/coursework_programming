#include "./../headers/interface.h"
#include "./../headers/functions.h"

void clearConsole()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void showTitleScreen()
{
	FILE *titleFile = fopen("..\\src\\data\\zast.txt", "r");
	char symbol;
	while (!feof(titleFile))
	{
		fscanf(titleFile, "%c", &symbol);
		printf("%c", symbol);
	}
	printf("\n");
	fclose(titleFile);
}

int getPressedKeyCode()
{
	#ifdef _WIN32
		return _getch();
	#else
		return 1
	#endif
}

int calculateMenuSize(const char *menuItems[])
{
	int index = 0;
	while (menuItems[index] != NULL)
	{
		index++;
	}
	return index;
}

void drawMenu(const char *menuItems[], int menuSize, int currentMenuItemIndex)
{
	for (int i = 0; i < menuSize; i++)
	{
		if (currentMenuItemIndex == i + 1)
		{
			printf("->");
		}
		else
		{
			printf("  ");
		}
		printf("%s\n", menuItems[i]);
	}
}

int getUserChoiceFromMenu(const char *menuItems[])
{
	const int MENU_SIZE = calculateMenuSize(menuItems);
	const int LAST_ACTIVE_INDEX = MENU_SIZE;
	int currentMenuItemIndex = FIRST_ACTIVE_INDEX;
	char pressedKey = '1';

	while (pressedKey != ENTER_KEY)
	{
		clearConsole();
		drawMenu(menuItems, MENU_SIZE, currentMenuItemIndex);
		pressedKey = getPressedKeyCode();

		switch (pressedKey)
		{
		case ARROW_DOWN:
		{
			currentMenuItemIndex++;
			if (currentMenuItemIndex == MENU_SIZE + 1)
			{
				currentMenuItemIndex = FIRST_ACTIVE_INDEX;
			}
			break;
		}
		case ARROW_UP:
		{
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
	clearConsole();
	return currentMenuItemIndex;
}
