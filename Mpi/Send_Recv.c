/**
 * Running Procedure:
 *
 * $ mpicc -o Send_Recv.o Send_Recv.c 
 * $ mpirun -n 4 Send_Recv.o
 */



#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "mpi.h"

int main(int argc, char const *argv[])
{
	int rank, size;
	MPI_Init(NULL , NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size < 2) {
    	fprintf(stderr, "Size must be greater than 1 for %s\n", argv[0]);
    	MPI_Abort(MPI_COMM_WORLD, 1);
  	}

  	int num1 = 5, num2 = 4, num3 = 15, num ;
  	if (rank == 0) {
    	MPI_Send(&num1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    	MPI_Send(&num2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    	MPI_Send(&num3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  	} else if (rank == 1) {
    	MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    	printf("Process 1 received number %d from process 0\n", num);
  	}
  	else if (rank == 2) {
    	MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    	printf("Process 2 received number %d from process 0\n", num);
  	}
  	else{
  		MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    	printf("Process 3 received number %d from process 0\n", num);
  	}
  	
	MPI_Finalize();
	return 0;
}