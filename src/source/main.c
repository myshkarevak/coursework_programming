#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/dataio.h"

int main()
{
	clearConsole();

	int numberOfPoints = requestNumberOfPoints();
	float *timePoints = (float *)calloc(numberOfPoints, sizeof(float));
	float *UInPoints = (float *)calloc(numberOfPoints, sizeof(float));
	float *UOutPoints = (float *)calloc(numberOfPoints, sizeof(float));

	printInitialValuesToConsole(numberOfPoints);
	calculateTimePoints(timePoints, numberOfPoints);
	calculateUInPoints(numberOfPoints, timePoints, UInPoints);
	calculateUOutPoints(numberOfPoints, UInPoints, UOutPoints);
	printCalculationToConsole
	(
		numberOfPoints, timePoints, UInPoints, UOutPoints
	);
	exportPointsDataToFile
	(
		TIME_POINTS_EXPORT_LOCATION, numberOfPoints, timePoints
	);
	exportPointsDataToFile
	(
		U_IN_POINTS_EXPORT_LOCATION, numberOfPoints, UInPoints
	);
	exportPointsDataToFile
	(
		U_OUT_POINTS_EXPORT_LOCATION, numberOfPoints, UOutPoints
	);
	calculateParametersWithGivenAccuracy(numberOfPoints);

	free(timePoints);
	free(UInPoints);
	free(UOutPoints);

	pauseSystem();

	return 0;
}