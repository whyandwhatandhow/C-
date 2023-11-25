#include<stdio.h>

void print() {
	printf("hello");
}

void printN1(int n) {
	for (int i = 1; i < n; i++) {
		printf("%d ", i);
	}
}

void printN2(int n) {
	if (n) {
		printN2(n - 1);
		printf("%d ", n);
	}

}