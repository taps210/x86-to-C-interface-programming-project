#include <immintrin.h>
#include <stdio.h> 
#include <stdlib.h> 

float c_dot_product(int n, float* A, float* B) {
    float dot_product = 0;

    for (int i = 0; i < n; i++) {
        dot_product += A[i] * B[i];
    }

    return dot_product;
}
