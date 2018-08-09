#include "stdio.h"
#include "stdlib.h"
#include "mpi.h"

int upperValue(float num){
	int tmp = num;
	if(num-tmp != 0.0)
		return tmp + 1;
	return tmp;
}

float calculateAvg(float nums[], int n){
	float sum = 0.0;
	//int n = sizeof(nums)/sizeof(nums[0]);
	for (int i = 0; i < n; ++i)
	{
		sum += nums[i];
		if(!nums[i])
			n--;
	}
	return (float)sum/n;
}

int main(int argc, char const *argv[])
{
	int numOfData = atoi(argv[1]);
	int size, rank;
	MPI_Init(NULL, NULL);
	MPI_Comm comm = MPI_COMM_WORLD;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	int numOfDataPerProcess = upperValue((float)numOfData/size);

	float data[numOfData];
	float dataPerProcess[numOfDataPerProcess];
	float allAvgs[size];
	if(rank==0){
		for(int i=0; i<numOfData; i++){
			scanf("%f", &data[i]);
		} 
	}
	//printf("Check%d %d %d\n", numOfData, numOfDataPerProcess, numOfProcess);

	MPI_Scatter(data, numOfDataPerProcess, MPI_FLOAT, dataPerProcess, numOfDataPerProcess, MPI_FLOAT, 0, comm);

	float avg;
	avg = calculateAvg(dataPerProcess, numOfDataPerProcess);

	MPI_Gather(&avg, 1, MPI_FLOAT, allAvgs, 1, MPI_FLOAT, 0, comm);

	if(rank==0){
		int n = sizeof(allAvgs)/sizeof(allAvgs[0]);
		for(int i=0; i<n; i++){
			int tmp = upperValue(allAvgs[i]);
			for(int j=0; j<tmp; j++){
				printf("#");
			}
			printf("\n");
		}
	}

	MPI_Barrier(comm);
  	MPI_Finalize();
	return 0;
}

//mpicc hist.c -o hist.o
//mpirun -n 4 hist.o 7  //here 7 is total number of data and 4 is the number of processes