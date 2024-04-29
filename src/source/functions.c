#include "./../headers/libraries.h"
#include "./../headers/functions.h"
#include "./../headers/dataio.h"

void calculateTimePoints(float timePoints[], const int NUMBER_OF_POINTS)
{
	const float STEP = (float)(TIME_END - TIME_START) / (NUMBER_OF_POINTS - 1);

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		timePoints[i] = TIME_START + i * STEP;	
	}
}

void calculateUInPoints
(
	const int NUMBER_OF_POINTS, float timePoints[], float UInPoints[]
)
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if (timePoints[i] <= TIME_BREAKPOINT_1) 
		{
			UInPoints[i] = 0;
		}
		else if 
		(
			timePoints[i] > TIME_BREAKPOINT_1
			&& timePoints[i] <= TIME_BREAKPOINT_2
		) 
		{
			UInPoints[i] =
				PARAMETER_A_U_IN * (timePoints[i] - TIME_BREAKPOINT_1);
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_2
			&& timePoints[i] <= TIME_BREAKPOINT_3
		)
		{
			UInPoints[i] =
				(PARAMETER_A_U_IN * (TIME_BREAKPOINT_2 - TIME_BREAKPOINT_1))
				- (PARAMETER_B_U_IN * (timePoints[i] - TIME_BREAKPOINT_2));
		}
		else if
		(
			timePoints[i] > TIME_BREAKPOINT_3
			&& timePoints[i] <= TIME_BREAKPOINT_4
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
	const int NUMBER_OF_POINTS, float UInPoints[], float UOutPoints[]
)
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		// if (UInPoints[i] <= PARAMETER_U1_U_OUT)
		// {
		// 		UOutPoints[i] =
		//			PARAMETER_A_U_OUT * UInPoints[i] + PARAMETER_B_U_OUT;
		// }
		// else if 
		// (
		// 		UInPoints[i] > PARAMETER_U1_U_OUT
		//		&& UInPoints[i] <= PARAMETER_U2_U_OUT
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
	const float INITIAL_VALUE,
	const float CURRENT_VALUE
)
{
	return fabs(INITIAL_VALUE - CURRENT_VALUE) / CURRENT_VALUE;
}

float calculateTimeDelta
(
	const float TIME_POINTS[]
)
{
	return TIME_POINTS[1] - TIME_POINTS[0];
}

float calculateMinUValue
(
	const int NUMBER_OF_POINTS,
	const float U_POINTS[]
)
{
	float minUValue = U_POINTS[0];

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if(U_POINTS[i] < minUValue)
		{
			minUValue = U_POINTS[i];
		}
	}

	return minUValue;
}

float calculateMaxUValue
(
	const int NUMBER_OF_POINTS,
	const float U_POINTS[]
)
{
	float maxUValue = U_POINTS[0];

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if(U_POINTS[i] > maxUValue)
		{
			maxUValue = U_POINTS[i];
		}
	}

	return maxUValue;
}

float calculateUBoundaryValue
(
	const float BOUNDARY,
	const int NUMBER_OF_POINTS,
	const float U_POINTS[]
)
{
	const float MIN_U = calculateMinUValue(NUMBER_OF_POINTS, U_POINTS);
	const float MAX_U = calculateMaxUValue(NUMBER_OF_POINTS, U_POINTS);

	return MIN_U + BOUNDARY * (MAX_U - MIN_U);
}

float calculateUVoltageMoment
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_POINTS[]
)
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if(U_POINTS[i] >= TARGET_VOLTAGE)
		{
			return TIME_POINTS[i];
		}
	}
	
	return -1;
}

float calculateUMaxMoment
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_POINTS[]
)
{
	const float MAX_U = calculateMaxUValue(NUMBER_OF_POINTS, U_POINTS);

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if(U_POINTS[i] == MAX_U)
		{
			return TIME_POINTS[i];
		}
	}

	return -1;
}

float calculateImpulseDuration
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_POINTS[]
)
{
	float pulseDuration = 0;
	const float TIME_DELTA = calculateTimeDelta(TIME_POINTS);
	const float IMPULSE_BOUNDARY_VALUE = calculateUBoundaryValue
		(
			IMPULSE_BOUNDARY, NUMBER_OF_POINTS, U_POINTS
		);
	
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if (U_POINTS[i] > IMPULSE_BOUNDARY_VALUE)
		{
			pulseDuration += TIME_DELTA;
		}
	}
	
	return pulseDuration;
}

float calculateSignalLeadingEdgeDuration 
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_POINTS[]
)
{
	float signalLeadingEdgeDuration = 0;
	const float TIME_DELTA = calculateTimeDelta(TIME_POINTS);

	const float LEADING_EDGE_START_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_STARTING_BOUNDARY, NUMBER_OF_POINTS, U_POINTS
		);
	const float LEADING_EDGE_END_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_ENDING_BOUNDARY, NUMBER_OF_POINTS, U_POINTS
		);
	
	// printf("\nLES: %f, \nLEE: %f", LEADING_EDGE_START_VALUE, LEADING_EDGE_END_VALUE);

	for(int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if
		(
			U_POINTS[i] > LEADING_EDGE_START_VALUE
			&& U_POINTS[i] < LEADING_EDGE_END_VALUE
			&& U_POINTS[i+1] > U_POINTS[i]
		)
		{
			signalLeadingEdgeDuration += TIME_DELTA;
		}
	}

	return signalLeadingEdgeDuration;
}

float calculateSignalRearEdgeDuration
(
	const int NUMBER_OF_POINTS,
	const float TIME_POINTS[],
	const float U_POINTS[]
)
{
	float signalRearEdgeDuration = 0;
	const float TIME_DELTA = calculateTimeDelta(TIME_POINTS);
	const float REAR_EDGE_START_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_ENDING_BOUNDARY, NUMBER_OF_POINTS, U_POINTS
		);
	const float REAR_EDGE_END_VALUE = calculateUBoundaryValue
		(
			SIGNAL_EDGE_STARTING_BOUNDARY, NUMBER_OF_POINTS, U_POINTS
		);

	for(int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if
		(
			U_POINTS[i] < REAR_EDGE_START_VALUE
			&& U_POINTS[i] > REAR_EDGE_END_VALUE
			&& U_POINTS[i+1] < U_POINTS[i]
		)
		{
			signalRearEdgeDuration += TIME_DELTA;
		}
	}

	return signalRearEdgeDuration;
}

void processParameterCalculationWithGivenAccuracy
(
	const char* PARAMETER_NAME,
	const int INITIAL_NUMBER_OF_POINTS,
	ParameterFunction parameterFunction
)
{
	const float targetError = TARGET_ACCURACY;
	float currentError = INITIAL_ACCURACY;
	float initialParameterValue = INITIAL_PARAMETER_VALUE;
	float currentParameterValue = 0;
	int numberOfPoints = INITIAL_NUMBER_OF_POINTS;

	printAccuracyCalculationTableHeader(PARAMETER_NAME);

	while (currentError > targetError)
	{
		float *timePoints = (float *)calloc(numberOfPoints, sizeof(float));
		float *UInPoints = (float *)calloc(numberOfPoints, sizeof(float));

		calculateTimePoints(timePoints, numberOfPoints);
		calculateUInPoints(numberOfPoints, timePoints, UInPoints);

		currentParameterValue = parameterFunction
			(
				numberOfPoints, timePoints,	UInPoints
			);
		currentError = calculateAccuracy
			(
				initialParameterValue, currentParameterValue
			);

		printAccuracyCalculationTableRow
		(
			numberOfPoints,
			currentParameterValue,
			currentError	
		);

		initialParameterValue = currentParameterValue;
		numberOfPoints *= 2;

		free(timePoints);
		free(UInPoints);
	}
}

void calculateParametersWithGivenAccuracy
(
	const int INITIAL_NUMBER_OF_POINTS
) 
{
	processParameterCalculationWithGivenAccuracy
	(
		"Moment of 80V voltage",
		INITIAL_NUMBER_OF_POINTS,
		calculateUVoltageMoment
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Moment of MAX voltage",
		INITIAL_NUMBER_OF_POINTS,
		calculateUMaxMoment
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Impulse duration",
		INITIAL_NUMBER_OF_POINTS,
		calculateImpulseDuration
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Leading edge duration",
		INITIAL_NUMBER_OF_POINTS,
		calculateSignalLeadingEdgeDuration
	);
	processParameterCalculationWithGivenAccuracy
	(
		"Rear edge duration",
		INITIAL_NUMBER_OF_POINTS,
		calculateSignalRearEdgeDuration
	);
	printf("\n");
}