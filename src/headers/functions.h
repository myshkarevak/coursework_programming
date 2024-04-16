#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#define TIME_START 5
#define TIME_BREAKPOINT_1 10
#define TIME_BREAKPOINT_2 15
#define TIME_BREAKPOINT_3 45
#define TIME_BREAKPOINT_4 50
#define TIME_END 60
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readInitialValuesFromConsole
(	
	int *numberOfPoints, float *inputParameterA,
	float *inputParameterB, float *inputParameterC,
	float *outputParameterA, float *outputParameterB,
	float *outputParameterU1, float *outputParameterU2
);

void printInitialValuesToConsole
(
	int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
 	float outputParameterA, float outputParameterB,
 	float outputParameterU1, float outputParameterU2
);

void saveInitialDataToFile
(
	const char *filePath, int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
 	float outputParameterA, float outputParameterB,
 	float outputParameterU1, float outputParameterU2
);

void loadInitialDataFromFile
(
	const char *filePath, int *numberOfPoints, float *inputParameterA,
	float *inputParameterB, float *inputParameterC,
	float *outputParameterA, float *outputParameterB,
	float *outputParameterU1, float *outputParameterU2
);

void calculateTimePoints
(
	float timePoints[], int numberOfPoints
);

void calculateUInPoints
(
	int numberOfPoints, float inputParameterA, float inputParameterB,
	float inputParameterC, float timePoints[], float UInPoints[]
);

void calculateUOutPoints
(
	int numberOfPoints, float outputParameterA,
	float outputParameterB, float outputParameterU1, 
	float outputParameterU2, float UInPoints[], float UOutPoints[]
);

void printCalculationToConsole
(
	int numberOfPoints, float timePoints[], float UInPoints[], float UOutPoints[]
);

void exportPointsDataToFile
(
	const char *filePath, int numberOfPoints, float timePoints[], float pointsData[]
);

#endif