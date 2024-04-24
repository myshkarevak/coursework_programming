#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define TIME_START 5
#define TIME_BREAKPOINT_1 10
#define TIME_BREAKPOINT_2 15
#define TIME_BREAKPOINT_3 45
#define TIME_BREAKPOINT_4 50
#define TIME_END 60

#define PARAMETER_A_U_IN 20
#define PARAMETER_B_U_IN 0.5
#define PARAMETER_C_U_IN 17
#define PARAMETER_A_U_OUT 2.5
#define PARAMETER_B_U_OUT 10
#define PARAMETER_U1_U_OUT 10
#define PARAMETER_U2_U_OUT 30

#define TARGET_ACCURACY 0.01
#define INITIAL_ACCURACY 1
#define INITIAL_PARAMETER_VALUE \
100000000.0

#define TARGET_VOLTAGE 80
#define IMPULSE_BOUNDARY 0.5
#define SIGNAL_EDGE_STARTING_BOUNDARY 0.1
#define SIGNAL_EDGE_ENDING_BOUNDARY 0.9

typedef float (*ParameterFunction)
(
	const int, const float[], const float[]
);

void calculateTimePoints
(
	float timePoints[],
	const int NUMBER_OF_POINTS
);

void calculateUInPoints
(
	const int NUMBER_OF_POINTS,
	float timePoints[],
	float UInPoints[]
);

void calculateUOutPoints
(
	const int NUMBER_OF_POINTS,
	float UInPoints[],
	float UOutPoints[]
);

void calculateParametersWithGivenAccuracy
(
	const int INITIAL_NUMBER_OF_POINTS
);

#endif