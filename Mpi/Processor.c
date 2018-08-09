/**
 * Running Procedure:
 *
 * $ mpicc -o Processor.o Processor.c 
 * $ mpirun -n 4 Processor.o
 */


#include <stdio.h>
#include "stdlib.h"
#include "mpi.h"

int main(int argc, char const *argv[])
{
	int rank, size;
	MPI_Init(NULL , NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

  	// Get the name of the processor
  	char processor_name[256];
  	int name_len;
  	MPI_Get_processor_name(processor_name, &name_len);
    printf("Number of processes : %d\nRank of processes : %d\nName of processes : %s\n", size, rank, processor_name );

	MPI_Finalize();
	return 0;
}