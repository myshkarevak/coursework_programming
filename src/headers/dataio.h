#ifndef DATAIO_H
#define DATAIO_H

#define _CRT_SECURE_NO_WARNINGS

#define TIME_POINTS_EXPORT_LOCATION \
"data/time.txt"
#define U_IN_POINTS_EXPORT_LOCATION \
"data/U_in.txt"
#define U_OUT_POINTS_EXPORT_LOCATION \
"data/U_out.txt"

void pauseSystem();
void clearConsole();

int requestNumberOfPoints();

void printInitialValuesToConsole
(
	int numberOfPoints
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

void printAccuracyCalculationTableHeader
(
	const char* PARAMETER_NAME
);

void printAccuracyCalculationTableRow
(
	const int numberOfPoints,
	const float parameterValue,
	const float error
);

#endif