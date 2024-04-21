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

void calculateTimePoints
(
	float timePoints[], int numberOfPoints
);

void calculateUInPoints
(
	int numberOfPoints, float timePoints[], float UInPoints[]
);

void calculateUOutPoints
(
	int numberOfPoints, float UInPoints[], float UOutPoints[]
);

void calculateParameterWithGivenAccuracy
(
	int numberOfPoints
);

#endif