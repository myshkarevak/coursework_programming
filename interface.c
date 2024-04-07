#include "functions.h"

int menu_draw_and_coise()
{
	int active_position = 1;
	char input = '1';

	while (input != 13)
	{
		system("cls");
		draw(active_position);
		input = _getch();
	
			if (input == 80)
			{
				active_position++;

				if (active_position == 10)
				{
					active_position = 1;
				}
			}
			else if (input == 72)
			{
				active_position--;

				if (active_position == 0)
				{
					active_position = 9;
				}
			}
	}
	return active_position;
}

void draw(int active_position)
{
	int par;
	if (active_position > 9 || active_position < 1)
	{
		return;
	}
		
	(active_position == 1) ? printf("->1: ������ ������ � ����������\n") : printf("  1: ������ ������ � ����������\n");
	(active_position == 2) ? printf("->2: ��������� ������ � ����\n") : printf("  2: ��������� ������ � ����\n");
	(active_position == 3) ? printf("->3: ��������� ������ �� �����\n") : printf("  3: ��������� ������ �� �����\n");
	(active_position == 4) ? printf("->4: ������� ������ wxmaxima\n") : printf("  4: ������� ������ wxmaxima\n");
	(active_position == 5) ? printf("->5: ��������� ������� ��� wxmaxima\n") : printf("  5: ��������� ������� ��� wxmaxim\n");
	(active_position == 6) ? printf("->6: �������� �������\n") : printf("  6: �������� �������\n");
	(active_position == 7) ? printf("->7: ������ �������� U_in\n") : printf("  7: ������ �������� U_in\n");
	(active_position == 8) ? printf("->8: ������ �������� U_out\n") : printf("  8: ������ �������� U_out\n");
	(active_position == 9) ? printf("->9: �����\n") : printf("  9: �����\n");
}

void print_zast()
{
	FILE* f = fopen("zast.txt", "r"); 
	char ch;
	while (!feof(f))                        
	{
		fscanf(f, "%c", &ch);             
		printf("%c", ch);
	}
	printf("\n");
	fclose(f);
}
