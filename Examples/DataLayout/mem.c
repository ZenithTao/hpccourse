#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv)
{
    int64_t size = 10000;
    int64_t i, j;
    srand(time(NULL));
    static int A[10000][10000];
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            A[i][j] = rand()%10;
        }
    }
    static int column_sum[10000];
    clock_t begin, end;
    double time_spent;

    begin = clock();
    // Simplistic approach to calculate column_sum without any regard to layout
    for(i = 0; i < size; i++) {
      column_sum[i] = 0;
      for(j = 0; j < size; j++) {
        column_sum[i] += A[j][i];
      }
    }
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent: %f\n", time_spent);
}
