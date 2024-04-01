// Group 4 - Bernardo, Fernandez - S16
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

extern float asmkernel(int n, float* A, float* B);
extern float c_dot_product(int n, float* A, float* B);

int main() {
    int i;
    int n = SIZE1; // vector size
    float value; // random value that will populate vectors
    float* A; // vectorA
    float* B; // vectorB
    float sdot; //output

    //timer
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for vectorA and vectorB dynamically
    A = (float*)malloc(n * sizeof(float));
    if (A == NULL) {
        printf(stderr, "Memory allocation failed\n");
        return 1;
    }
    B = (float*)malloc(n * sizeof(float));
    if (B == NULL) {
        printf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize vectors with random values
    for (i = 0; i < n; i++) {
        value = (float)rand() / RAND_MAX * MAX;
        A[i] = value;
        value = (float)rand() / RAND_MAX * MAX;
        B[i] = value;
    }

    //call asmkernel
    //time the execution of asmkernel
    start = clock();
    sdot = asmkernel(n, A, B);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    sdot = asmkernel(n, A, B);
    printf("Dot Product of asm kernel: %f\n", sdot);
    printf("Time taken by asm kernel: %f seconds\n", cpu_time_used);

    //call ckernel
    //time the execution of c_dot_product
    start = clock();
    sdot = c_dot_product(n, A, B);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    sdot = c_dot_product(n, A, B);
    printf("\nDot Product: %f\n", sdot);
    printf("Time taken by c_dot_product: %f seconds\n", cpu_time_used);

    // Free dynamically allocated memory
    free(A);
    free(B);

    return 0;
}