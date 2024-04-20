#ifndef DATAIO_H
#define DATAIO_H

#define _CRT_SECURE_NO_WARNINGS
#define INITIAL_DATA_IMPORT_LOCATION \
"../src/data/initial_data.txt"
#define INITIAL_DATA_EXPORT_LOCATION \
"../export/initial_data.txt"
#define TIME_POINTS_EXPORT_LOCATION \
"../export/time.txt"
#define U_IN_POINTS_EXPORT_LOCATION \
"../export/U_in.txt"
#define U_OUT_POINTS_EXPORT_LOCATION \
"../export/U_out.txt"

void clearConsole();

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

void exportInitialDataToFile
(
	const char *filePath, int numberOfPoints,
	float inputParameterA, float inputParameterB,
	float inputParameterC, float outputParameterA,
	float outputParameterB, float outputParameterU1,
	float outputParameterU2
);

void loadInitialDataFromFile
(
	const char *filePath, int *numberOfPoints,
	float *inputParameterA, float *inputParameterB,
	float *inputParameterC,	float *outputParameterA,
	float *outputParameterB, float *outputParameterU1,
	float *outputParameterU2
);

void printCalculationToConsole
(
	int numberOfPoints, float timePoints[],
	float UInPoints[], float UOutPoints[]
);

void exportPointsDataToFile
(
	const char *filePath, int numberOfPoints,
	float pointsData[]
);

#endif