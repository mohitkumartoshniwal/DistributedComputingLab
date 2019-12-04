#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

int id,size;
int magic_number;
double start,end;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&id);
MPI_Comm_size(MPI_COMM_WORLD,&size);




//fflush(0);

start=MPI_Wtime();
MPI_Barrier(MPI_COMM_WORLD);

    if (id == 0){
	magic_number = rand();

	}

MPI_Bcast(&magic_number,1,MPI_INT,0,MPI_COMM_WORLD);

printf("Rank %d received magic number %d.\n", id,magic_number);


MPI_Barrier(MPI_COMM_WORLD);

end=MPI_Wtime();

printf(" Time taken for %d is %f\n",id,end-start); 

   
MPI_Finalize();


}
