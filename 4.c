#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
		int a[4][3],b[3][4],c[4][4],i,j,k;

		omp_set_num_threads(4);//set 
		
		#pragma omp parallel for
		for(i=0;i<4;i++){
		for(int j=0;j<3;j++)
			a[i][j]=i+j;
		}
	
		#pragma omp parallel for
		for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			b[i][j]=i*j;
		}			
		

		#pragma omp parallel for
		for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			c[i][j]=0;
		}

		#pragma omp parallel for
		for(i=0;i<4;i++){
		printf("Execution of %d row done by %d\n",i,omp_get_thread_num());
		for(j=0;j<4;j++){
			for(k=0;k<3;k++)
				c[i][j]+=a[i][k]*b[k][j];

		}
			
		}

		printf("Result is\n");
		for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%d ",c[i][j]);
		printf("\n");
		}
		


					
		






}
