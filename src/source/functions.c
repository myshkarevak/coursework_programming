#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/menu.h"

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
	clearConsole();
	printf("Points: "); scanf("%d", numberOfPoints);
	printf("Parameter A for U_in: ");   scanf("%f", inputParameterA);
	printf("Parameter B for U_in: ");   scanf("%f", inputParameterB);
	printf("Parameter C for U_in: "); scanf("%f", inputParameterC);
	printf("Parameter A for U_out: "); scanf("%f", outputParameterA);
	printf("Parameter B for U_out: "); scanf("%f", outputParameterB);
	printf("Parameter U1 for U_out: "); scanf("%f", outputParameterU1);
	printf("Parameter U2 for U_out: "); scanf("%f", outputParameterU2);
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
	printf("Points: %d\n", numberOfPoints);
	printf("Parameter A for U_in: %f\n", inputParameterA);
	printf("Parameter B for U_in: %f\n", inputParameterB);
	printf("Parameter C for U_in: %f\n", inputParameterC);
	printf("Parameter A for U_out: %f\n", outputParameterA);
	printf("Parameter B for U_out: %f\n", outputParameterB);
	printf("Parameter U1 for U_out: %f\n", outputParameterU1);
	printf("Parameter U2 for U_out: %f\n", outputParameterU2);
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
	// FILE* data = fopen("src\\data\\data.txt", "w");
	clearConsole();
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
	// FILE* outputFile = fopen("src\\data\\data.txt", "r");
	clearConsole();
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
}

void calculateTimePoints(float timePoints[], int numberOfPoints)
{
   float step = (TIME_END - TIME_START) / (numberOfPoints - 1);

	for (int i = 0; i < numberOfPoints; i++)
	{
		timePoints[i] = TIME_START + i * step;	
	}
}

void calculateUInPoints
(
	int numberOfPoints, float inputParameterA, float inputParameterB,
	float inputParameterC, float timePoints[], float UInPoints[]
)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
			if
			(
				timePoints[i] <= TIME_BREAKPOINT_1
			) 
			{
				UInPoints[i] = 0;
			}
			else if 
			(
				timePoints[i] > TIME_BREAKPOINT_1 && timePoints[i] < TIME_BREAKPOINT_2
			) 
			{
				UInPoints[i] =
				inputParameterA * (timePoints[i] - TIME_BREAKPOINT_1);
			}
			else if
			(
				timePoints[i] > TIME_BREAKPOINT_2 && timePoints[i] < TIME_BREAKPOINT_3
			)
			{
				UInPoints[i] =
					(inputParameterA * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
					- (inputParameterB * (timePoints[i] - TIME_BREAKPOINT_2));
			}
			else if
			(
				timePoints[i] > TIME_BREAKPOINT_3 && timePoints[i] < TIME_BREAKPOINT_4
			)
			{
				UInPoints[i] = 
					(inputParameterA * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
					- (inputParameterB * (TIME_BREAKPOINT_3 - TIME_BREAKPOINT_2))
					- (inputParameterC * (timePoints[i] - TIME_BREAKPOINT_3));
			}
			else
			{
				UInPoints[i] = 0;
			}
	}
}

void calculateUOutPoints
(
	int numberOfPoints, float outputParameterA,
	float outputParameterB, float outputParameterU1, 
	float outputParameterU2, float UInPoints[],
	float UOutPoints[]
)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		// if(UInPoints[i] <= outputParameterU1)
		// {
		// 	UOutPoints[i] = outputParameterA * UInPoints[i] + outputParameterB;
		// }
		// else if (UInPoints[i] > outputParameterU1 && UInPoints[i] <= outputParameterU2)
		// {
		// 	UOutPoints[i] = outputParameterA * UInPoints[i] + outputParameterB;
		// } 
		// else 
		// {
		// 	UOutPoints[i] = outputParameterA * UInPoints[i] + outputParameterB;
		// }
		UOutPoints[i] =
			outputParameterA * UInPoints[i] + outputParameterB;
	}
}

void printCalculationToConsole
(
	int numberOfPoints, float timePoints[],
	float UInPoints[], float UOutPoints[]
)
{	
	printf("Point\t|\tTime\t|\tU_in\t|\tU_out\t|\n");

	for (int i = 0; i < numberOfPoints; i++)     
	{
		printf
		(
			"%d\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\n",
			i + 1,
			timePoints[i],
			UInPoints[i],
			UOutPoints[i]
		);
	}
}

void exportPointsDataToFile
(
	const char *filePath, int numberOfPoints,
	float timePoints[], float pointsData[]
)
{
	FILE* exportFile = fopen(filePath, "w");

	for (int i = 0; i < numberOfPoints; i++)
	{
		fprintf(exportFile, "%.4f\t%.4f\n", timePoints[i], pointsData[i]);
	}

	fclose(exportFile);
}

void calculateParameterWithGivenAccuracy
(
	int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
 	float outputParameterA, float outputParameterB,
 	float outputParameterU1, float outputParameterU2
) 
{
	// TODO
}

// float dlitelnost(int N, float U[], float dt, float U_imp)
// {
// 	float dlit = 0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		if (U[i] >= U_imp)
// 		{
// 			dlit += dt;
// 		}
// 	}
// 	return dlit;
// }

// float outsortMax(float U_out[], int N)
// {
// 	int x = 0;
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		if (U_out[i] < U_out[i + 1])
// 		{
// 			x = i + 1;
// 		}
// 	}
// 	return U_out[x];
// }

// float outsortMin(float U_out[], int N)
// {
// 	int x = 0;
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		if (U_out[i] > U_out[i + 1])
// 		{
// 			x = i + 1;
// 		}
// 	}
// 	return U_out[x];
// }

// void accurancy(int N, float U, float a_in, float a1_out,
// 	float a2_out, float a3_out, float a4_out,
// 	float b1_out, float b2_out, float b3_out,
// 	float b4_out, float U_in1, float U_in2, float U_in3, int para)
// {
// 	float eps;
// 	printf("\n : ");
// 	scanf("%f", &eps);

// 	double p = 1;

// 	double par = 1000000; 

// 	float dlit;

// 	int n = N;

// 	while (p > eps)
// 	{
// 		float* time = NULL, * U_in = NULL, * U_out = NULL;
// 		time = (float*)calloc(n, sizeof(float));
// 		U_in = (float*)calloc(n, sizeof(float));
// 		U_out = (float*)calloc(n, sizeof(float));
// 		float dt = (2*PI - PI) / (n - 1);

// 		create_time(time, n, PI, 2*PI);
// 		create_U_in(n, a_in, U, time, U_in);
// 		create_U_out(n, U_out, U_in1, U_in2, U_in3, a1_out,
// 		a2_out, a3_out, a4_out, b1_out, b2_out,
// 		b3_out, b4_out, U_in);

// 		if (para == 1)
// 		{
// 			float Umax = outsortMax(U_in, n) ;
// 			float Umin = outsortMin(U_in, n);
// 			float Uimp = Umin + 0.5 * (Umax - Umin);
// 			 dlit = dlitelnost(n, U_in, dt, Uimp);
// 		}
// 		else
// 		{
// 			float Umax = outsortMax(U_out, n);

// 			float Umin = outsortMin(U_out, n);

// 			float Uimp = Umin + 0.5 * (Umax - Umin);
// 			 dlit = dlitelnost(n, U_in, dt, Uimp);
// 		}
		

// 		p = fabs(par - dlit) / dlit;

// 		printf("n = %d parametr = %f pogrechnost = %lf\n", n, dlit, p);

// 		par = dlit;

// 		n = 2 * n;

// 		free(time);
// 		free(U_in);
// 		free(U_out);
// 	}

// 	system("pause");
// }