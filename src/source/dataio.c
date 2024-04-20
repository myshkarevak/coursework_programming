
#include "./../headers/libraries.h"
#include "./../headers/dataio.h"

void clearConsole()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void readInitialValuesFromConsole
(	
	int *numberOfPoints, float *inputParameterA,
	float *inputParameterB, float *inputParameterC,
	float *outputParameterA, float *outputParameterB,
	float *outputParameterU1, float *outputParameterU2
)
{
	printf("Please, input the Initial data:\n\n");
	printf("Points: "); scanf("%d", numberOfPoints);
	printf("Parameter A for U_in: "); scanf("%f", inputParameterA);
	printf("Parameter B for U_in: "); scanf("%f", inputParameterB);
	printf("Parameter C for U_in: "); scanf("%f", inputParameterC);
	printf("Parameter A for U_out: "); scanf("%f", outputParameterA);
	printf("Parameter B for U_out: "); scanf("%f", outputParameterB);
	printf("Parameter U1 for U_out: "); scanf("%f", outputParameterU1);
	printf("Parameter U2 for U_out: "); scanf("%f", outputParameterU2);
	printf("\nInput completed\n\n");
}

void printInitialValuesToConsole
(
	int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
 	float outputParameterA, float outputParameterB,
 	float outputParameterU1, float outputParameterU2
)
{
	clearConsole();
	printf("Initial data:\n\n");
	printf
	(
		"[\t%s\t][\t%s\t]\n",
		"Parameter",
		"Value"
	);
	printf("|\tPoints  \t||\t%d\t|\n", numberOfPoints);
	printf("|\tA for U_in\t||\t%.3f\t|\n", inputParameterA);
	printf("|\tB for U_in\t||\t%.3f\t|\n", inputParameterB);
	printf("|\tC for U_in\t||\t%.3f\t|\n", inputParameterC);
	printf("|\tA for U_out\t||\t%.3f\t|\n", outputParameterA);
	printf("|\tB for U_out\t||\t%.3f\t|\n", outputParameterB);
	printf("|\tU1 for U_out\t||\t%.3f\t|\n", outputParameterU1);
	printf("|\tU2 for U_out\t||\t%.3f\t|\n", outputParameterU2);
	printf("\n");
}

void exportInitialDataToFile
(
	const char *filePath, int numberOfPoints,
	float inputParameterA, float inputParameterB,
	float inputParameterC,float outputParameterA,
	float outputParameterB, float outputParameterU1,
	float outputParameterU2
)
{
	clearConsole();
	printf("Export to [%s] started...\n", filePath);
	FILE* outputFile = fopen(filePath, "w");

	fprintf(outputFile, "Points: %d\n", numberOfPoints);
	fprintf(outputFile, "Parameter A for U_in: %f\n", inputParameterA);
	fprintf(outputFile, "Parameter B for U_in: %f\n", inputParameterB);
	fprintf(outputFile, "Parameter C for U_in: %f\n", inputParameterC);
	fprintf(outputFile, "Parameter A for U_out: %f\n", outputParameterA);
	fprintf(outputFile, "Parameter B for U_out: %f\n", outputParameterB);
	fprintf(outputFile, "Parameter U1 for U_out: %f\n", outputParameterU1);
	fprintf(outputFile, "Parameter U2 for U_out: %f\n", outputParameterU2);

	fclose(outputFile);
	printf("Export finished\n\n");
}

void loadInitialDataFromFile
(
	const char* filePath, int *numberOfPoints,
	float *inputParameterA, float *inputParameterB,
	float *inputParameterC,	float *outputParameterA,
	float *outputParameterB, float *outputParameterU1,
	float *outputParameterU2
)
{
	clearConsole();
	printf("Reading data from file...\n");
	FILE* inputFile = fopen(filePath, "r");

	fscanf(inputFile, "Points: %d\n", numberOfPoints);
	fscanf(inputFile, "Parameter A for U_in: %f\n", inputParameterA);
	fscanf(inputFile, "Parameter B for U_in: %f\n", inputParameterB);
	fscanf(inputFile, "Parameter C for U_in: %f\n", inputParameterC);
	fscanf(inputFile, "Parameter A for U_out: %f\n", outputParameterA);
	fscanf(inputFile, "Parameter B for U_out: %f\n", outputParameterB);
	fscanf(inputFile, "Parameter U1 for U_out: %f\n", outputParameterU1);
	fscanf(inputFile, "Parameter U2 for U_out: %f\n", outputParameterU2);

	fclose(inputFile);
	printf("Data read successfully\n\n");
}

void printCalculationToConsole
(
	int numberOfPoints, float timePoints[],
	float UInPoints[], float UOutPoints[]
)
{	
	printf("Calculation:\n\n");
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
	printf("Export finished\n\n");
}