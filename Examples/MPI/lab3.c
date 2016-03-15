#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{
int rank, size;
MPI_Init(NULL, NULL); 
MPI_Comm_rank (MPI_COMM_WORLD, &rank);
MPI_Comm_size (MPI_COMM_WORLD, &size);
int send_msg = 27;
int recv_msg;
int dest;
MPI_Status status;
if(rank == size-1)
   dest = 0;
else
   dest = rank+1;

MPI_Send(&send_msg, sizeof(send_msg), MPI_INT, dest, 22, MPI_COMM_WORLD);
MPI_Recv(&recv_msg, 20, MPI_INT, MPI_ANY_SOURCE, 22, MPI_COMM_WORLD, &status);

printf("%d got %d from %d\n",rank, recv_msg, status.MPI_SOURCE);
fflush(stdout);
MPI_Finalize();
}
