#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define testcase1 pow(2, 20)
#define testcase2 pow(2, 24)
#define testcase3 pow(2, 28)

//extern double asmkernel(int n, double *A, double*B);

int main() {
	int i;
	int n = testcase1; // vector size
	double valueA = 12.43; // repeatedly used value for vectorB
	double valueB = 84.69; // repeatedly used value for vectorB
	double* A; // vectorA
	double* B; // vectorB
	double sdot;

	// Allocate memory for vectorA and vectorB dynamically
	A = (double*)malloc(n * sizeof(double));
	if (A == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	B = (double*)malloc(n * sizeof(double));
	if (B == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}

	// Initialize vectors with values
	for (i = 0; i < n; i++) {
		A[i] = valueA;
		B[i] = valueB;
	}

	//call asmkernel
	//sdot = asmkernel(n, &A, &B);

	// Free dynamically allocated memory
	free(A);
	free(B);

	return 0;
}