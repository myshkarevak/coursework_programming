#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/dataio.h"

void calculateTimePoints(float timePoints[], int numberOfPoints)
{
	float step = (float)(TIME_END - TIME_START) / (numberOfPoints - 1);

	for (int i = 0; i < numberOfPoints; i++)
	{
		timePoints[i] = TIME_START + i * step;	
	}
}

void calculateUInPoints
(
	int numberOfPoints, float timePoints[], float UInPoints[]
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
				PARAMETER_A_U_IN * (timePoints[i] - TIME_BREAKPOINT_1);
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_2 && timePoints[i] < TIME_BREAKPOINT_3
		)
		{
			UInPoints[i] =
				(PARAMETER_A_U_IN * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
				- (PARAMETER_B_U_IN * (timePoints[i] - TIME_BREAKPOINT_2));
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_3 && timePoints[i] < TIME_BREAKPOINT_4
		)
		{
			UInPoints[i] = 
				(PARAMETER_A_U_IN * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
				- (PARAMETER_B_U_IN * (TIME_BREAKPOINT_3 - TIME_BREAKPOINT_2))
				- (PARAMETER_C_U_IN * (timePoints[i] - TIME_BREAKPOINT_3));
		}
		else
		{
			UInPoints[i] = 0;
		}
	}
}

void calculateUOutPoints
(
	int numberOfPoints, float UInPoints[], float UOutPoints[]
)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		// if(UInPoints[i] <= PARAMETER_U1_U_OUT)
		// {
		// 	UOutPoints[i] = PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// }
		// else if (UInPoints[i] > PARAMETER_U1_U_OUT && UInPoints[i] <= PARAMETER_U2_U_OUT)
		// {
		// 	UOutPoints[i] = PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// } 
		// else 
		// {
		// 	UOutPoints[i] = PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// }

		UOutPoints[i] =
			PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
	}
}

float calculateAccuracy
(
	float initialValue,
	float currentValue
)
{
	return fabs(initialValue - currentValue) / currentValue;
}

void processParameterCalculationWithGivenAccuracy
(
	char* parameterName,
	ParameterFunction parameterFunction,
	int initialNumberOfPoints
)
{
	float currentAccuracy = 1;
	float targetAccuracy = 0.01;
	float initialParameterValue = 100000000.0;
	float currentParameterValue = 0;
	int numberOfPoints = initialNumberOfPoints;

	printAccuracyCalculationTableHeader();

	while (currentAccuracy > targetAccuracy)
	{
		float *timePoints = (float *)calloc(numberOfPoints, sizeof(float));
		float *UInPoints = (float *)calloc(numberOfPoints, sizeof(float));
		float *UOutPoints = (float *)calloc(numberOfPoints, sizeof(float));

		calculateTimePoints(timePoints, numberOfPoints);
		calculateUInPoints(numberOfPoints, timePoints, UInPoints);
		calculateUOutPoints(numberOfPoints, UInPoints, UOutPoints);

		currentParameterValue = parameterFunction
			(
				numberOfPoints, timePoints,
				UInPoints, UOutPoints
			);
		currentAccuracy = calculateAccuracy
			(
				initialParameterValue,
				currentParameterValue
			);

		printAccuracyCalculationTableRow();

		initialParameterValue = currentParameterValue;
		numberOfPoints *= 2;

		free(timePoints);
		free(UInPoints);
		free(UOutPoints);
	}
}

void calculateParametersWithGivenAccuracy
(
	int numberOfPoints
) 
{
	// TODO
}