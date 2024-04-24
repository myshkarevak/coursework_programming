#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/dataio.h"

int main()
{
	clearConsole();

	const int NUMBER_OF_POINTS = requestNumberOfPoints();
	float *timePoints = (float *)calloc(NUMBER_OF_POINTS, sizeof(float));
	float *UInPoints = (float *)calloc(NUMBER_OF_POINTS, sizeof(float));
	float *UOutPoints = (float *)calloc(NUMBER_OF_POINTS, sizeof(float));

	printInitialValuesToConsole(NUMBER_OF_POINTS);
	calculateTimePoints(timePoints, NUMBER_OF_POINTS);
	calculateUInPoints(NUMBER_OF_POINTS, timePoints, UInPoints);
	calculateUOutPoints(NUMBER_OF_POINTS, UInPoints, UOutPoints);
	printCalculationToConsole
	(
		NUMBER_OF_POINTS, timePoints, UInPoints, UOutPoints
	);
	exportPointsDataToFile
	(
		TIME_POINTS_EXPORT_LOCATION, NUMBER_OF_POINTS, timePoints
	);
	exportPointsDataToFile
	(
		U_IN_POINTS_EXPORT_LOCATION, NUMBER_OF_POINTS, UInPoints
	);
	exportPointsDataToFile
	(
		U_OUT_POINTS_EXPORT_LOCATION, NUMBER_OF_POINTS, UOutPoints
	);
	calculateParametersWithGivenAccuracy(NUMBER_OF_POINTS);

	free(timePoints);
	free(UInPoints);
	free(UOutPoints);

	pauseSystem();

	return 0;
}