#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
// TODO define cls if Windows, clear if Linux
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> //TODO #include <curses.h>

void showTitleScreen();

int getUserChoiceFromMenu(const char* menuItems[]);

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
	float timePoints[], int numberOfPoints, float timeStart, float timeEnd
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