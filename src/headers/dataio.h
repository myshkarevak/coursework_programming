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
	const int NUMBER_OF_POINTS
);

void printCalculationToConsole
(
	int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_IN_POINTS[],
	const float U_OUT_POINTS[]
);

void exportPointsDataToFile
(
	const char *FILE_PATH,
	const int NUMBER_OF_POINTS,
	const float POINTS_DATA[]
);

void printAccuracyCalculationTableHeader
(
	const char* PARAMETER_NAME
);

void printAccuracyCalculationTableRow
(
	const int NUMBER_OF_POINTS,
	const float PARAMETER_VALUE,
	const float ERROR_VALUE
);

#endif