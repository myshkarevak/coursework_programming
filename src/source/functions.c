#include "./../headers/libraries.h"
#include "./../headers/functions.h"

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

void calculateParameterWithGivenAccuracy
(
	int numberOfPoints
) 
{
	// TODO
}

// float dlitelnost(int N, float U[], float dt, float U_imp)
// {
// 	float dlit = 0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		if (U[i] >= U_imp)
// 		{
// 			dlit += dt;
// 		}
// 	}
// 	return dlit;
// }

// float outsortMax(float U_out[], int N)
// {
// 	int x = 0;
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		if (U_out[i] < U_out[i + 1])
// 		{
// 			x = i + 1;
// 		}
// 	}
// 	return U_out[x];
// }

// float outsortMin(float U_out[], int N)
// {
// 	int x = 0;
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		if (U_out[i] > U_out[i + 1])
// 		{
// 			x = i + 1;
// 		}
// 	}
// 	return U_out[x];
// }

// void accurancy(int N, float U, float a_in, float a1_out,
// 	float a2_out, float a3_out, float a4_out,
// 	float b1_out, float b2_out, float b3_out,
// 	float b4_out, float U_in1, float U_in2, float U_in3, int para)
// {
// 	float eps;
// 	printf("\n : ");
// 	scanf("%f", &eps);

// 	double p = 1;

// 	double par = 1000000; 

// 	float dlit;

// 	int n = N;

// 	while (p > eps)
// 	{
// 		float* time = NULL, * U_in = NULL, * U_out = NULL;
// 		time = (float*)calloc(n, sizeof(float));
// 		U_in = (float*)calloc(n, sizeof(float));
// 		U_out = (float*)calloc(n, sizeof(float));
// 		float dt = (2*PI - PI) / (n - 1);

// 		create_time(time, n, PI, 2*PI);
// 		create_U_in(n, a_in, U, time, U_in);
// 		create_U_out(n, U_out, U_in1, U_in2, U_in3, a1_out,
// 		a2_out, a3_out, a4_out, b1_out, b2_out,
// 		b3_out, b4_out, U_in);

// 		if (para == 1)
// 		{
// 			float Umax = outsortMax(U_in, n) ;
// 			float Umin = outsortMin(U_in, n);
// 			float Uimp = Umin + 0.5 * (Umax - Umin);
// 			 dlit = dlitelnost(n, U_in, dt, Uimp);
// 		}
// 		else
// 		{
// 			float Umax = outsortMax(U_out, n);

// 			float Umin = outsortMin(U_out, n);

// 			float Uimp = Umin + 0.5 * (Umax - Umin);
// 			 dlit = dlitelnost(n, U_in, dt, Uimp);
// 		}
		

// 		p = fabs(par - dlit) / dlit;

// 		printf("n = %d parametr = %f pogrechnost = %lf\n", n, dlit, p);

// 		par = dlit;

// 		n = 2 * n;

// 		free(time);
// 		free(U_in);
// 		free(U_out);
// 	}

// 	system("pause");
// }