#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//fixed vector sizes
#define SIZE1 pow(2, 20)
#define SIZE2 pow(2, 24)
#define SIZE3 pow(2, 28)
//maximum value of randomly generated values
#define MAX 20

//extern double asmkernel(int n, double *A, double*B);
//extern float c_dot_product(int n, double *A, double *B, double *sdot)

int main() {
	int i;
	int n = SIZE1; // vector size
	double value; // random value that will populate vectors
	double* A; // vectorA
	double* B; // vectorB
	double sdot; //output

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

	// Initialize vectors with random values
	for (i = 0; i < n; i++) {
		value = (double)rand() / RAND_MAX * MAX;
		A[i] = value;
		value= (double)rand() / RAND_MAX * MAX;
		B[i] = value;
	}

	printf("Initialized array of double precision floating point values:\n");
	for (i = 0; i < n; i++) {
		printf("%f  %f\n", A[i], B[i]);
	}
	
	//call asmkernel
	//sdot = asmkernel(n, &A, &B);

	//call ckernel
	//sdot = c_dot_product(n, A, B, &sdot);
	//printf("Dot Product: %.2f\n", sdot);

	// Free dynamically allocated memory
	free(A);
	free(B);

	return 0;
}