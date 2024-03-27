#include <immintrin.h>

float c_dot_product(int n, double* A, double* B, double* sdot) {
    __m256d sum = _mm256_setzero_pd();

    for (int i = 0; i < n; i += 4) {
        __m256d a = _mm256_loadu_pd(&A[i]);
        __m256d b = _mm256_loadu_pd(&B[i]);
        sum = _mm256_add_pd(sum, _mm256_mul_pd(a, b));
    }

    double result[4];
    _mm256_storeu_pd(result, sum);

    *sdot = result[0] + result[1] + result[2] + result[3];

    return *sdot;
}