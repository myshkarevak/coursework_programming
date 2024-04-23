
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
	getchar(); //remove \n from input
	return value;
}

void printInitialValuesToConsole
(
	int numberOfPoints
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
	printf("|\tPoints  \t||\t%d\t|\n", numberOfPoints);
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
	int numberOfPoints, float timePoints[],
	float UInPoints[], float UOutPoints[]
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

	for (int i = 0; i < numberOfPoints; i++)     
	{
		printf
		(
			"|\t%d\t||\t%8.4f\t||\t%8.4f\t||\t%8.4f\t|\n",
			i + 1,
			timePoints[i],
			UInPoints[i],
			UOutPoints[i]
		);
	}
	printf("\n");
}

void exportPointsDataToFile
(
	const char *filePath, int numberOfPoints,
	float pointsData[]
)
{
	printf("Export to [%s] started...\n", filePath);
	FILE* exportFile = fopen(filePath, "w");

	for (int i = 0; i < numberOfPoints; i++)
	{
		fprintf(exportFile, "%.4f\n", pointsData[i]);
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
	printf("[\tN\t][\tValue\t][\tError\t]\n");
}

void printAccuracyCalculationTableRow
(
	const int numberOfPoints,
	const float parameterValue,
	const float error
)
{
	printf
	(
		"|\t%d\t||\t%.3f\t||\t%.3f\t|\n",
		numberOfPoints,
		parameterValue,
		error > 1000 ? INFINITY : error
	);
}