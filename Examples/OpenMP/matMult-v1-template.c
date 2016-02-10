#include <assert.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
int A[N][N], B[N][1];
int C[N][1], C1[N][1];

int main(void) {
  int i, j, k;
  double Start, End;

  srand((int)time(NULL));
  for (i = 0; i < N; ++i) {
    B[i][1] = rand() % 10;
    for (j = 0; j < N; ++j) {
      A[i][j] = rand() % 10;
    }
  }
  printf("---- Serial\n");
  Start = omp_get_wtime();
  for (i = 0; i < N; ++i) {
      int Sum = 0;
      for (k = 0; k < N; ++k) {
        Sum += A[i][k] * B[k][1];
      }
      C[i][1] = Sum;
  }
  End = omp_get_wtime();
  printf("---- Serial done in %f seconds.\n", End - Start);
  printf("---- Parallel\n");
omp_set_dynamic(0);     // Explicitly disable dynamic teams
omp_set_num_threads(4); // Use 4 threads for all consecutive parallel regions

  Start = omp_get_wtime();

//Store your result in C1[N][1]

  End = omp_get_wtime();
  printf("---- Parallel done in %f seconds.\n", End - Start);
  printf("---- Check\n");
  for (i = 0; i < N; i++) {
      assert (C[i][1] == C1[i][1]);
  }
  printf("Passed\n");
  return 0;
}
