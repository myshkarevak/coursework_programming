#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define TIME_START 5
#define TIME_BREAKPOINT_1 10
#define TIME_BREAKPOINT_2 15
#define TIME_BREAKPOINT_3 45
#define TIME_BREAKPOINT_4 50
#define TIME_END 60

void calculateTimePoints
(
	float timePoints[], int numberOfPoints
);

void calculateUInPoints
(
	int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
	float timePoints[], float UInPoints[]
);

void calculateUOutPoints
(
	int numberOfPoints, float outputParameterA,
	float outputParameterB, float outputParameterU1, 
	float outputParameterU2, float UInPoints[],
	float UOutPoints[]
);

void calculateParameterWithGivenAccuracy
(
	int numberOfPoints, float inputParameterA,
	float inputParameterB, float inputParameterC,
 	float outputParameterA, float outputParameterB,
 	float outputParameterU1, float outputParameterU2
);

#endif