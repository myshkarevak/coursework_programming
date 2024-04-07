#ifndef DATA_H
#define DATA_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define PI 3.1416

void print_zast();
int menu_draw_and_coise();
void draw(int active_position);

void input(int* N, float* U, float* a_in, float* a1_out,
	float* a2_out, float* a3_out, float* a4_out,
	float* b1_out, float* b2_out, float* b3_out,
	float* b4_out, float* U_in1, float* U_in2, float* U_in3);

void save_data(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3);

void load_data(int* N, float* U, float* a_in, float* a1_out,
	float* a2_out, float* a3_out, float* a4_out,
	float* b1_out, float* b2_out, float* b3_out,
	float* b4_out, float* U_in1, float* U_in2, float* U_in3);

void create_time(float time[], int N, float time_start, float time_end);

void create_U_in(int N, float a, float U, float time[], float U_in[]);

void create_U_out(int N, float U_out[], float U_in1, float U_in2, 
	float U_in3, float a1_out, float a2_out, float a3_out, float a4_out,
 	 float b1_out, float b2_out, float b3_out, float b4_out, float U_in[]);

void print_data(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3);
void print_to_console(int N, float time[], float U_in[], float U_out[]);

void print_to_file(int N, float time[], float U_in[], float U_out[]);

void accurancy(int N, float U, float a_in, float a1_out,
	float a2_out, float a3_out, float a4_out,
	float b1_out, float b2_out, float b3_out,
	float b4_out, float U_in1, float U_in2, float U_in3, int para);

#endif