/*
 * Change the number of threads, here, when running on the cluster
 */

#include <assert.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// On cluster this will be much larger
#define N 10000

/* These are defined here because if
 * inside main, they go on the stack,
 * and you will overflow very quickly
 */
int A[N][N], B[N];
int Cs[N], Cp[N];

int main(void) {
    int i, j, k;
    double Start, End;

    srand((int)time(NULL));
    for (i = 0; i < N; ++i) {
        B[i] = rand() % 10;
        for (j = 0; j < N; ++j) {
            A[i][j] = rand() % 10;
        }
    }
    printf("---- Serial\n");
    Start = omp_get_wtime();
    for (i = 0; i < N; i++) {
        int Sum = 0;
        for (j = 0; j < N; j++) {
            Sum += A[i][j] * B[j];
        }
        Cs[i] = Sum;
    }
    End = omp_get_wtime();
    printf("---- Serial done in %f seconds\n", End - Start);
    printf("---- Parallel\n");
    omp_set_dynamic(0); // Explicitly disable dynamic teams
    omp_set_num_threads(8); // Use 4 threads for all consecutive parallel regions

    Start = omp_get_wtime();
    /*
     * Implement this and store your
     * results in Cp[N]
     */
    End = omp_get_wtime();
    printf("---- Parallel done in %f seconds\n", End - Start);
    printf("---- Check\n");
    for (i = 0; i < N; i++) {
        assert (Cs[i] == Cp[i]);
    }
    printf("Passed\n");

    return 0;
}
