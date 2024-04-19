#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/menu.h"

// TODO
// 4 parameters with accuracy
// menu in batch with maxima
// linux support c
// sh scripts
// title screen

int main()
{	
	// system("chcp 1251");
	clearConsole();

	int choice = 0, numberOfPoints = 0;
	float inputParameterA = 0, inputParameterB = 0,
		inputParameterC = 0, outputParameterA = 0,
		outputParameterB = 0, outputParameterU1 = 0,
		outputParameterU2 = 0, *timePoints = NULL,
		*UInPoints = NULL, *UOutPoints = NULL;

	while (choice != EXIT_CASE)
	{
		choice = getUserChoiceFromMenu();
		clearConsole();
		switch (choice)
		{
			case CONSOLE_INPUT_CASE:
			{
				readInitialValuesFromConsole
				(	
					&numberOfPoints, &inputParameterA,
					&inputParameterB, &inputParameterC,
					&outputParameterA, &outputParameterB,
					&outputParameterU1, &outputParameterU2
				);
				system("pause");
				printInitialValuesToConsole
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);
				break;
			}
			case FILE_INPUT_CASE:
			{
				loadInitialDataFromFile
				(
					INITIAL_DATA_IMPORT_LOCATION,
					&numberOfPoints, &inputParameterA,
					&inputParameterB, &inputParameterC,
					&outputParameterA, &outputParameterB,
					&outputParameterU1, &outputParameterU2
				);
				system("pause");
				printInitialValuesToConsole
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);
				break;
			}
			case SAVE_INPUT_CASE:
			{
				exportInitialDataToFile
				(	
					INITIAL_DATA_EXPORT_LOCATION,
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);
				break;
			}
			case CALCULATE_DATA_CASE:
			{	
				printInitialValuesToConsole
				(	
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);

				timePoints = (float*)calloc(numberOfPoints, sizeof(float));
				UInPoints = (float*)calloc(numberOfPoints, sizeof(float));
				UOutPoints = (float*)calloc(numberOfPoints, sizeof(float));

				calculateTimePoints(timePoints, numberOfPoints);
				calculateUInPoints
				(
					numberOfPoints,	inputParameterA,
					inputParameterB, inputParameterC, 
					timePoints, UInPoints
				);
				calculateUOutPoints
				(
					numberOfPoints,	outputParameterA,
					outputParameterB, outputParameterU1, 
					outputParameterU2,	UInPoints,
					UOutPoints
				);
				printCalculationToConsole
				(
					numberOfPoints, timePoints,
					UInPoints, UOutPoints
				);
				break;
			}
			case EXPORT_CALCULATION_CASE:
			{
				if (timePoints == NULL || UInPoints == NULL || UOutPoints == NULL)
				{
					printf("\nerror! no data to save please create that first\n");
					system("pause");
					break;
				}

				exportPointsDataToFile
				(
					TIME_POINTS_EXPORT_LOCATION,
					numberOfPoints,	timePoints
				);
				exportPointsDataToFile
				(
					U_IN_POINTS_EXPORT_LOCATION,
					numberOfPoints, UInPoints
				);
				exportPointsDataToFile
				(
					U_OUT_POINTS_EXPORT_LOCATION,
					numberOfPoints, UOutPoints
				);
				break;
			}
			case CALCULATE_WITH_ACCURACY_CASE:
			{
				calculateParameterWithGivenAccuracy
				(
					numberOfPoints, inputParameterA,
					inputParameterB, inputParameterC,
					outputParameterA, outputParameterB,
					outputParameterU1, outputParameterU2
				);
				break;
			}
			case EXIT_CASE:
			{	
				free(timePoints);
				free(UInPoints);
				free(UOutPoints);
				return 0;
			}
		}
		system("pause");
	}

	return 1;
}