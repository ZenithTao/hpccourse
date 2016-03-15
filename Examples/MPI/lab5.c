#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)
{
  int message;
  int  i, rank, size;
  MPI_Status status;
  int root = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == root)
  {
     message = 20;
  }
  MPI_Bcast(&message, sizeof(message), MPI_INT, root, MPI_COMM_WORLD);
  if (rank != root)
     printf( "Message from process %d : %d\n", rank, message);

  MPI_Finalize();
}
