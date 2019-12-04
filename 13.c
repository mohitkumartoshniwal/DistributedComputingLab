#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

int partner,i;
int myrank,size;
char greeting[100];


MPI_Status stat;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

sprintf(greeting,"Processor rank %d of %d\n",myrank,size);

if(myrank==0)
{
	fputs(greeting,stdout);
	for(partner=1;partner<size;partner++){
	MPI_Recv(greeting,sizeof(greeting),MPI_BYTE,partner,1,MPI_COMM_WORLD,&stat);
	fputs(greeting,stdout);
	}


}
else
{

	MPI_Send(greeting,strlen(greeting)+1,MPI_BYTE,0,1,MPI_COMM_WORLD);

}

if(myrank==0)
{

	printf("Thats all for now\n");
}

MPI_Finalize();


}
