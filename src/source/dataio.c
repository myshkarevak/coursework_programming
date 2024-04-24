#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/dataio.h"

void pauseSystem()
{
	printf("press ENTER key to continue...\n");
	getchar();
}

void clearConsole()
{
	system("clear");
}

int requestNumberOfPoints()
{
	int value;
	printf("Number of points: ");
	scanf("%d", &value);
	getchar(); // remove \n from input buffer
	return value;
}

void printInitialValuesToConsole
(
	const int NUMBER_OF_POINTS
)
{
	clearConsole();
	printf("Initial data:\n");
	printf
	(
		"[\t%s\t][\t%s\t]\n",
		"Parameter",
		"Value"
	);
	printf("|\tPoints (N)\t||\t%d\t|\n", NUMBER_OF_POINTS);
	printf("|\tA for U_in\t||\t%d\t|\n", PARAMETER_A_U_IN);
	printf("|\tB for U_in\t||\t%.1f\t|\n", PARAMETER_B_U_IN);
	printf("|\tC for U_in\t||\t%d\t|\n", PARAMETER_C_U_IN);
	printf("|\tA for U_out\t||\t%.1f\t|\n", PARAMETER_A_U_OUT);
	printf("|\tB for U_out\t||\t%d\t|\n", PARAMETER_B_U_OUT);
	printf("|\tU1 for U_out\t||\t%d\t|\n", PARAMETER_U1_U_OUT);
	printf("|\tU2 for U_out\t||\t%d\t|\n", PARAMETER_U2_U_OUT);
	printf("\n");
}

void printCalculationToConsole
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_IN_POINTS[],
	const float U_OUT_POINTS[]
)
{	
	printf("Calculation:\n");
	printf
	(
		"[\t%s\t][\t%8s\t][\t%8s\t][\t%8s\t]\n",
		"N",
		"Time",
		"U_in",
		"U_out"
	);

	for (int i = 0; i < NUMBER_OF_POINTS; i++)     
	{
		printf
		(
			"|\t%d\t||\t%8.4f\t||\t%8.4f\t||\t%8.4f\t|\n",
			i + 1,
			TIME_POINTS[i],
			U_IN_POINTS[i],
			U_OUT_POINTS[i]
		);
	}
	printf("\n");
}

void exportPointsDataToFile
(
	const char *FILE_PATH,
	const int NUMBER_OF_POINTS,
	const float POINTS_DATA[]
)
{
	FILE* exportFile = fopen(FILE_PATH, "w");

	printf("Export to [%s] started...\n", FILE_PATH);

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		fprintf(exportFile, "%.4f\n", POINTS_DATA[i]);
	}

	fclose(exportFile);
	printf("Export finished\n");
}

void printAccuracyCalculationTableHeader
(
	const char* PARAMETER_NAME
)
{
	printf("\n%s\n", PARAMETER_NAME);
	printf
	(
		"[\t%s\t][\t%8s\t][\t%8s\t]\n",
		"N",
		"Value",
		"Error"
	);
}

void printAccuracyCalculationTableRow
(
	const int NUMBER_OF_POINTS,
	const float PARAMETER_VALUE,
	const float ERROR_VALUE
)
{
	printf
	(
		"|\t%d\t||\t%8.4f\t||\t%8.4f\t|\n",
		NUMBER_OF_POINTS,
		PARAMETER_VALUE,
		ERROR_VALUE > 1000 ? INFINITY : ERROR_VALUE
	);
}