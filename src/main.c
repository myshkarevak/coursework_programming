#include "./headers/functions.h"
#include "./headers/interface.h"
// TODO use arrows to navigate message
const char* menuItems[] = 
	{
		"1. Input initial data from console",
		"2. Load initial data from file",
		"3. Save initial data to file",
		"4. Calculate data", 
		"5. Export calculation",
		// "6. Calculate and print U_in duration with accuracy",
		// "7. Calculate and print U_out duration with accuracy",
		"6. Exit",
		NULL // TODO
	};
const int EXIT_INDEX = 6; // TODO

int main()
{	
	// system("chcp 1251");
	// system("pause");

	clearConsole();
	showTitleScreen();
	system("pause");

	int choice = 0, numberOfPoints = 0;
	float inputParameterA = 0, inputParameterB = 0, inputParameterC = 0,
		outputParameterA = 0,outputParameterB = 0, outputParameterU1 = 0,
		outputParameterU2 = 0, timeStart = 0, timeEnd = 0,
		*timePoints = NULL, *UInPoints = NULL, *UOutPoints = NULL;

	while (choice != EXIT_INDEX)
	{
		choice = getUserChoiceFromMenu(menuItems);

		switch (choice)
		{
		case 1:
			{
				readInitialValuesFromConsole // TODO if data have errors
				(	
					&numberOfPoints, &inputParameterA,
					&inputParameterB, &inputParameterC,
					&outputParameterA, &outputParameterB,
					&outputParameterU1, &outputParameterU2
				);

				clearConsole();
				printf("Initial data:\n\n");

				printInitialValuesToConsole // TODO if data have errors
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);

				system("pause");
				break;
			}
		case 2:
			{
				loadInitialDataFromFile // TODO if file has no values
				(
					"data/initial.txt", &numberOfPoints, &inputParameterA,
					&inputParameterB, &inputParameterC,
					&outputParameterA, &outputParameterB,
					&outputParameterU1, &outputParameterU2
				);

				clearConsole();
				printf("Initial data:\n\n");

				printInitialValuesToConsole // TODO if data have errors
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);

				system("pause");
				break;
			}
		case 3:
			{
				saveInitialDataToFile // TODO if data have errors
				(	
					"data/initial.txt", numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);

				system("pause");
				break;
			}
		case 4:
			{	
				printInitialValuesToConsole // TODO if data have errors
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);

				// TODO
				// if (time != NULL || U_in != NULL || U_out != NULL)
				// {
				// 	free(time);
				// 	free(U_in);
				// 	free(U_out);
				// }

				timePoints = (float*)calloc(numberOfPoints, sizeof(float));
				UInPoints = (float*)calloc(numberOfPoints, sizeof(float));
				UOutPoints = (float*)calloc(numberOfPoints, sizeof(float));

				calculateTimePoints(timePoints, numberOfPoints, timeStart, timeEnd);

				calculateUInPoints
				(
					numberOfPoints, 
					inputParameterA,
					inputParameterB,
					inputParameterC, 
					timePoints,
					UInPoints
				);

				calculateUOutPoints
				(
					numberOfPoints,
					outputParameterA,
					outputParameterB,
					outputParameterU1, 
					outputParameterU2,
					UInPoints,
					UOutPoints
				);

				printCalculationToConsole
				(
					numberOfPoints,
					timePoints,
					UInPoints,
					UOutPoints
				);

				system("pause");
				break;
			}
		case 5:
		{
			// TODO
			// if (time == NULL || U_in == NULL || U_out == NULL)
			// {
			// 	printf("\nerror! no data to save please create that first\n");
			// 	system("pause");
			// 	break;
			// }
			exportPointsDataToFile("data/U_in.txt", numberOfPoints, timePoints, UInPoints);
			exportPointsDataToFile("data/U_out.txt", numberOfPoints, timePoints, UOutPoints);
			system("pause");
			break;
		}
		// case 6:
		// {
		// 	accurancy(N, U, a_in, a1_out,
		// 		a2_out, a3_out, a4_out,
		// 		b1_out, b2_out, b3_out,
		// 		b4_out, U_in1, U_in2, U_in3, 1);
		// 	system("pause");
		// 	break;
		// }
		// case 7:
		// {
		// 	accurancy(N, U, a_in, a1_out,
		// 		a2_out, a3_out, a4_out,
		// 		b1_out, b2_out, b3_out,
		// 		b4_out, U_in1, U_in2, U_in3, 0);
		// 	system("pause");
		// 	break;
		// }
		case 6:
		{	
			free(timePoints);
			free(UInPoints);
			free(UOutPoints);

			printf("exit...");

			return 0;
		}
		}
	}
}