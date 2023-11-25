#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void printN1(int n);
void printN2(int n);
void print();
double merge1(int n, double a[], double x);
double merge2(int n, double a[], double x);

void main() {

	
}



clock_t start, stop;

double duringTime;

void test() {
	start = clock();
	//Your test adhere


	stop = clock();
	duringTime = ((double)(start - stop)) / CLK_TCK;
	printf("%f", duringTime);
}
