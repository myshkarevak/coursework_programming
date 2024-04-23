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
		if (timePoints[i] <= TIME_BREAKPOINT_1) 
		{
			UInPoints[i] = 0;
		}
		else if 
		(
			timePoints[i] > TIME_BREAKPOINT_1
				&& timePoints[i] < TIME_BREAKPOINT_2
		) 
		{
			UInPoints[i] =
				PARAMETER_A_U_IN * (timePoints[i] - TIME_BREAKPOINT_1);
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_2
				&& timePoints[i] < TIME_BREAKPOINT_3
		)
		{
			UInPoints[i] =
				(PARAMETER_A_U_IN * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
				- (PARAMETER_B_U_IN * (timePoints[i] - TIME_BREAKPOINT_2));
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_3
				&& timePoints[i] < TIME_BREAKPOINT_4
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
		// if (UInPoints[i] <= PARAMETER_U1_U_OUT)
		// {
		// 		UOutPoints[i] =
		//			PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// }
		// else if 
		// (
		// 		UInPoints[i] > PARAMETER_U1_U_OUT
		//			&& UInPoints[i] <= PARAMETER_U2_U_OUT
		// )
		// {
		// 		UOutPoints[i] =
		//			PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// } 
		// else 
		// {
		// 		UOutPoints[i] =
		// 			PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
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

float calculateTimeDelta
(
	float time[]
)
{
	return time[1] - time[0];
}

float calculateMinUValue
(
	int numberOfPoints,
	float UPoints[]
)
{
	float minUValue = UPoints[0];

	for (int i =0; i < numberOfPoints; i++)
	{
		if(UPoints[i] < minUValue)
		{
			minUValue = UPoints[i];
		}
	}

	return minUValue;
}

float calculateMaxUValue
(
	int numberOfPoints,
	float UPoints[]
)
{
	float maxUValue = UPoints[0];

	for (int i = 0; i < numberOfPoints; i++)
	{
		if(UPoints[i] > maxUValue)
		{
			maxUValue = UPoints[i];
		}
	}

	return maxUValue;
}

float calculateUBoundaryValue
(
	const float BOUNDARY,
	int numberOfPoints,
	float UPoints[]
)
{
	const float MAX_U = calculateMinUValue(numberOfPoints, UPoints);
	const float MIN_U = calculateMaxUValue(numberOfPoints, UPoints);

	return MIN_U + BOUNDARY * (MAX_U - MIN_U);
}

float calculateUVoltageMoment
(
	int numberOfPoints,
	float time[],
	float UPoints[]
)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		if(UPoints[i] >= TARGET_VOLTAGE)
		{
			return time[i];
		}
	}
	
	return -1;
}

float calculateUMaxMoment
(
	int numberOfPoints,
	float time[],
	float UPoints[]
)
{
	const float MAX_U = calculateMinUValue(numberOfPoints, UPoints);

	for (int i = 0; i < numberOfPoints; i++)
	{
		if(UPoints[i] == MAX_U)
		{
			return time[i];
		}
	}

	return -1;
}

float calculateImpulseDuration
(
	int numberOfPoints,
	float time[],
	float UPoints[]
)
{
	float pulseDuration = 0;
	const float timeDelta = calculateTimeDelta(time);
	const float UImpulseBoundaryValue = calculateUBoundaryValue
		(
			IMPULSE_BOUNDARY, numberOfPoints, UPoints
		);
	
	for (int i = 0; i < numberOfPoints; i++)
	{
		if (UPoints[i] > UImpulseBoundaryValue)
		{
			pulseDuration += timeDelta;
		}
	}
	
	return pulseDuration;
}

float calculateSignalLeadingEdgeDuration 
( // similar to REAR
	int numberOfPoints,
	float time[],
	float UPoints[]
)
{
	float signalLeadingEdgeDuration = 0;
	const float timeDelta = calculateTimeDelta(time);
	const float LEADING_EDGE_START_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_STARTING_BOUNDARY, numberOfPoints, UPoints
		);
	const float LEADING_EDGE_END_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_ENDING_BOUNDARY, numberOfPoints, UPoints
		);

	for(int i = 0; i < numberOfPoints; i++)
	{
		if
		(
			UPoints[i] > LEADING_EDGE_START_VALUE
				&& UPoints[i] > LEADING_EDGE_END_VALUE
				&& UPoints[i+1] > UPoints[i]
		)
		{
			signalLeadingEdgeDuration += timeDelta;
		}
	}

	return signalLeadingEdgeDuration;
}

float calculateSignalRearEdgeDuration
(
	int numberOfPoints,
	float time[],
	float UPoints[]
)
{
	float signalRearEdgeDuration = 0;
	const float timeDelta = calculateTimeDelta(time);
	const float REAR_EDGE_START_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_STARTING_BOUNDARY, numberOfPoints, UPoints
		);
	const float REAR_EDGE_END_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_ENDING_BOUNDARY, numberOfPoints, UPoints
		);

	for(int i = 0; i < numberOfPoints; i++)
	{
		if
		(
			UPoints[i] > REAR_EDGE_START_VALUE
				&& UPoints[i] > REAR_EDGE_END_VALUE
				&& UPoints[i+1] < UPoints[i]
		)
		{
			signalRearEdgeDuration += timeDelta;
		}
	}

	return signalRearEdgeDuration;
}

void processParameterCalculationWithGivenAccuracy
(
	const char* PARAMETER_NAME,
	ParameterFunction parameterFunction,
	int initialNumberOfPoints
)
{
	const float targetAccuracy = TARGET_ACCURACY;
	float currentAccuracy = INITIAL_ACCURACY;
	float initialParameterValue = INITIAL_PARAMETER_VALUE;
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
		// calculateUOutPoints(numberOfPoints, UInPoints, UOutPoints);

		currentParameterValue = parameterFunction
			(
				numberOfPoints, timePoints,
				UInPoints
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
	processParameterCalculationWithGivenAccuracy
	(
		"Moment of 80V voltage",
		calculateUVoltageMoment,
		numberOfPoints
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Moment of MAX voltage",
		calculateUMaxMoment,
		numberOfPoints
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Impulse duration",
		calculateImpulseDuration,
		numberOfPoints
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Leading edge duration",
		calculateSignalLeadingEdgeDuration,
		numberOfPoints
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Rear edge duration",
		calculateSignalRearEdgeDuration,
		numberOfPoints
	);
}