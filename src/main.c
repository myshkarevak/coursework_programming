#include "./headers/functions.h"

int main()
{	
	system("chcp 1251");
	system("cls");
	print_zast();
	system("pause");

	int N = 0;
	float time_start = PI, time_end = 2 * PI;
	float dt = 0, a_in = 0, a1_out = 0, a2_out = 0, a3_out = 0, a4_out = 0;
	float U = 0, b1_out = 0, b2_out = 0, b3_out = 0, b4_out = 0, U_in1=0 , U_in2 =0, U_in3=0;
	float* time = NULL, * U_in = NULL, * U_out = NULL;
	int choise = 0;

	while (1)
	{
		choise = menu_draw_and_coise();

		switch (choise)
		{
		case 1:
			{
			input(&N, &U, &a_in, &a1_out,
				&a2_out, &a3_out, &a4_out,
				&b1_out, &b2_out, &b3_out,
				&b4_out, &U_in1, &U_in2, &U_in3);
	
			printf("created");
			system("pause");
			break;
			}
		case 2:
		{
			save_data(N, U, a_in, a1_out,
				a2_out, a3_out, a4_out,
				b1_out, b2_out, b3_out,
				b4_out,U_in1, U_in2, U_in3);
			
			printf("\nsaved!\n");
			system("pause");
			break;
		}
		case 3:
		{
			load_data(&N, &U, &a_in, &a1_out,
				&a2_out, &a3_out, &a4_out,
				&b1_out, &b2_out, &b3_out,
				&b4_out, &U_in1, &U_in2, &U_in3);

			printf("\nloaded!\n");
			system("pause");
			break;
		}
		case 4:
		{
			system("calculation.wxmx");
			system("pause");
			break;
		}
		case 5:
		{
			if (time == NULL || U_in == NULL || U_out == NULL)
			{
				printf("\nerror! no data to save please create that first\n");
				system("pause");
				break;
			}
			print_to_file(N, time, U_in, U_out);
			system("graph.wxm");
			system("pause");
			break;
		}
		case 6:
		{	
			print_data(N, U, a_in, a1_out,
				a2_out, a3_out, a4_out,
				b1_out, b2_out, b3_out,
				b4_out, U_in1, U_in2, U_in3);

			if (time != NULL || U_in != NULL || U_out != NULL)
			{
				free(time);
				free(U_in);
				free(U_out);
			}

			time = (float*)calloc(N, sizeof(float));
			U_in = (float*)calloc(N, sizeof(float));
			U_out = (float*)calloc(N, sizeof(float));

			create_time(time, N, time_start, time_end);
			create_U_in(N, a_in, U, time, U_in);
			create_U_out(N, U_out, U_in1, U_in2, U_in3, a1_out,
				a2_out, a3_out, a4_out, b1_out, b2_out,
				b3_out, b4_out, U_in);
			print_to_console(N, time, U_in, U_out);

			printf("\nprinted!\n");
			system("pause");
			break;
		}
		case 7:
		{
			accurancy(N, U, a_in, a1_out,
				a2_out, a3_out, a4_out,
				b1_out, b2_out, b3_out,
				b4_out, U_in1, U_in2, U_in3, 1);
			system("pause");
			break;
		}
		case 8:
		{
			accurancy(N, U, a_in, a1_out,
				a2_out, a3_out, a4_out,
				b1_out, b2_out, b3_out,
				b4_out, U_in1, U_in2, U_in3, 0);
			system("pause");
			break;
		}
		case 9:
		{	
			free(time);
			free(U_in);
			free(U_out);
			printf("exit...");
			return 0;
		}
		}
	}
}