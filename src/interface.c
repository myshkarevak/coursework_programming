#include "./headers/functions.h"

const char* menuItems[] = 
	{
		"1. Input data from console\n",
		"2. Save data to file\n",
		"3. Load data from file\n",
		"4. Open WXMaxima calculation\n",
		"5. Save calculations to files\n",
		"6. Print calculations\n", 
		"7. Calculate and print U_in duration with accuracy\n",
		"8. Calculate and print U_out duration with accuracy\n",
		"9. Exit\n",
	};

int calculateMenuSize()
{
	return (&menuItems)[1] - menuItems;
}

int menu_draw_and_coise()
{
	printf("1");
	const int MENU_SIZE = calculateMenuSize();
	int active_position = 1;
	char input = '1';

	while (input != 13)
	{
		system("cls");
		draw(active_position, MENU_SIZE);
		input = _getch();
	
			if (input == 80)
			{
				active_position++;

				if (active_position == MENU_SIZE + 1)
				{
					active_position = 1;
				}
			}
			else if (input == 72)
			{
				active_position--;

				if (active_position == 0)
				{
					active_position = MENU_SIZE;
				}
			}
	}
	system("cls");
	return active_position;
}

void draw(int active_position, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(active_position == i + 1)
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

void print_zast()
{
	FILE* f = fopen("src\\data\\zast.txt", "r"); 
	char ch;
	while (!feof(f))                        
	{
		fscanf(f, "%c", &ch);             
		printf("%c", ch);
	}
	printf("\n");
	fclose(f);
}
