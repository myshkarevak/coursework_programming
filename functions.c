#include "functions.h"

void input(int *N, float *U, float *a_in, float *a1_out,
	float *a2_out, float *a3_out, float *a4_out,
	float *b1_out, float *b2_out, float *b3_out,
	float *b4_out, float *U_in1, float *U_in2, float *U_in3)
{
	printf("N: "); scanf("%d", N);
	printf("U: ");   scanf("%f", U);
	printf("a: ");   scanf("%f", a_in);
	printf("a1: "); scanf("%f", a1_out);
	printf("a2: "); scanf("%f", a2_out);
	printf("a3: "); scanf("%f", a3_out);
	printf("4: "); scanf("%f", a4_out);
	printf("b1: "); scanf("%f", b1_out);
	printf("b2: "); scanf("%f", b2_out);
	printf("b3: "); scanf("%f", b3_out);
	printf("b4: "); scanf("%f", b4_out);
	printf("U_in1: "); scanf("%f", U_in1);
	printf("U_in2: "); scanf("%f", U_in2);
	printf("U_in3: "); scanf("%f", U_in3);
}

void save_data(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3)
{

	FILE* data;
	data = fopen("data.txt", "w");

	fprintf(data, "N = %d\n", N);
	fprintf(data, "U = %f\n", U);
	fprintf(data, "a_in = %f\n", a_in);
	fprintf(data, "a1_out = %f\n", a1_out);
	fprintf(data, "a2_out = %f\n", a2_out);
	fprintf(data, "a3_out = %f\n", a3_out);
	fprintf(data, "a4_out = %f\n", a4_out);
	fprintf(data, "b1_out = %f\n", b1_out);
	fprintf(data, "b2_out = %f\n", b2_out);
	fprintf(data, "b3_out = %f\n", b3_out);
	fprintf(data, "b4_out = %f\n", b4_out);
	fprintf(data, "U_in1 = %f\n", U_in1);
	fprintf(data, "U_in2 = %f\n", U_in2);
	fprintf(data, "U_in3 = %f\n", U_in3);

	fclose(data);
}

void load_data(int* N, float* U, float* a_in, float* a1_out,
	float* a2_out, float* a3_out, float* a4_out,
	float* b1_out, float* b2_out, float* b3_out,
	float* b4_out, float* U_in1, float* U_in2, float* U_in3)
{
	FILE* data = fopen("data.txt", "a");
	fclose(data);
	data = fopen("data.txt", "r");

	fscanf(data, "N = %d\n", N);
	fscanf(data, "U = %f\n", U);
	fscanf(data, "a_in = %f\n", a_in);
	fscanf(data, "a1_out = %f\n", a1_out);
	fscanf(data, "a2_out = %f\n", a2_out);
	fscanf(data, "a3_out = %f\n", a3_out);
	fscanf(data, "a4_out = %f\n", a4_out);
	fscanf(data, "b1_out = %f\n", b1_out);
	fscanf(data, "b2_out = %f\n", b2_out);
	fscanf(data, "b3_out = %f\n", b3_out);
	fscanf(data, "b4_out = %f\n", b4_out);
	fscanf(data, "U_in1 = %f\n", U_in1);
	fscanf(data, "U_in2 = %f\n", U_in2);
	fscanf(data, "U_in3 = %f\n", U_in3);

	fclose(data);
}

void create_time(float time[], int N, float time_start, float time_end)
{
   float dt = (time_end - time_start) / (N - 1);

	for (int i = 0; i < N; i++)
	{
		time[i] = time_start + i * dt;	
	}
}

void create_U_in(int N, float a, float U, float time[], float U_in[])
{
	for (int i = 0; i < N; i++)
	{
			U_in[i] = (U * exp(-1 * a * time[i])) * sin(time[i]);
	}
}

void create_U_out(int N,float U_out[], float U_in1, 
	float U_in2, float U_in3, float a1_out, float a2_out, 
	float a3_out, float a4_out, float b1_out, float b2_out,
	float b3_out, float b4_out, float U_in[])
{
	for (int i = 0; i < N; i++)
	{
		if (U_in[i] <= U_in1)
		{
			U_out[i] = (a1_out * U_in[i]) + b1_out;
		}
		else if (U_in[i] > U_in1&& U_in[i] <= U_in2)
		{
			U_out[i] = (a2_out * U_in[i]) + b2_out;
		}
		else if (U_in[i] > U_in[2] && U_in[i] <= U_in3)
		{
			U_out[i] = (a3_out * U_in[i]) + b3_out;
		}
		else if (U_in[i] > U_in3)
		{
			U_out[i] = (a4_out * U_in[i]) + b4_out;
		}
	}
}

void print_to_console(int N, float time[], float U_in[], float U_out[])
{	
	printf("   N   time      U_in       U_out");
	for (int i = 0; i < N; i++) //     
	{
		printf("\n % 3d % .6f % .6f % .6f", i, time[i], U_in[i], U_out[i]);
	}
}

void print_data(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3)
{
	printf("a: %d\n", N);                 
	printf("U: %f\n", U);  
	printf("a1: %f\n", a_in);   
	printf("a1: %f\n", a1_out); 
	printf("a2: %f\n", a2_out); 
	printf("a3: %f\n", a3_out); 
	printf("4: %f\n", a4_out); 
	printf("b1: %f\n", b1_out); 
	printf("b2: %f\n", b2_out); 
	printf("b3: %f\n", b3_out); 
	printf("b4: %f\n", b4_out); 
	printf("U_in1: %f\n", U_in1); 
	printf("U_in2: %f\n", U_in2); 
	printf("U_in3: %f\n", U_in3); 
}

void print_to_file(int N, float time[], float U_in[], float U_out[])
{
	FILE* arr_t, * arr_Uin, * arr_Uout, * data;

	arr_t = fopen("arr_t.txt", "w");
	arr_Uin = fopen("arr_Uin.txt", "w");
	arr_Uout = fopen("arr_Uout.txt", "w");
	for (int i = 0; i < N; i++)
	{
		fprintf(arr_t, "\n %6.3f", time[i]);
		fprintf(arr_Uin, "\n %6.3f", U_in[i]);         
		fprintf(arr_Uout, "\n%6.3f", U_out[i]);
	}
	fclose(arr_t);
	fclose(arr_Uin);
	fclose(arr_Uout);
}

float dlitelnost(int N, float U[], float dt, float U_imp)
{
	float dlit = 0;
	for (int i = 0; i < N; i++)
	{
		if (U[i] >= U_imp)
		{
			dlit += dt;
		}
	}
	return dlit;
}

float outsortMax(float U_out[], int N)
{
	int x = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (U_out[i] < U_out[i + 1])
		{
			x = i + 1;
		}
	}
	return U_out[x];
}

float outsortMin(float U_out[], int N)
{
	int x = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (U_out[i] > U_out[i + 1])
		{
			x = i + 1;
		}
	}
	return U_out[x];
}


void accurancy(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3, int para)
{
	float eps;
	printf("\n : ");
	scanf("%f", &eps);

	double p = 1;

	double par = 1000000; 

	float dlit;

	int n = N;

	while (p > eps)
	{
		float* time = NULL, * U_in = NULL, * U_out = NULL;
		time = (float*)calloc(n, sizeof(float));
		U_in = (float*)calloc(n, sizeof(float));
		U_out = (float*)calloc(n, sizeof(float));
		float dt = (2*PI - PI) / (n - 1);

		create_time(time, n, PI, 2*PI);
		create_U_in(n, a_in, U, time, U_in);
		create_U_out(n, U_out, U_in1, U_in2, U_in3, a1_out,
		a2_out, a3_out, a4_out, b1_out, b2_out,
		b3_out, b4_out, U_in);

		if (para == 1)
		{
			float Umax = outsortMax(U_in, n) ;
			float Umin = outsortMin(U_in, n);
			float Uimp = Umin + 0.5 * (Umax - Umin);
			 dlit = dlitelnost(n, U_in, dt, Uimp);
		}
		else
		{
			float Umax = outsortMax(U_out, n);

			float Umin = outsortMin(U_out, n);

			float Uimp = Umin + 0.5 * (Umax - Umin);
			 dlit = dlitelnost(n, U_in, dt, Uimp);
		}
		

		p = fabs(par - dlit) / dlit;

		printf("n = %d parametr = %f pogrechnost = %lf\n", n, dlit, p);

		par = dlit;

		n = 2 * n;

		free(time);
		free(U_in);
		free(U_out);
	}

	system("pause");
}