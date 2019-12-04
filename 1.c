#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main(){

int a[100],b[100],c[100],d[100],i;

for(i=0;i<100;i++)
{

	a[i]=b[i]=i*10;
}

	#pragma omp parallel num_threads(8)
	{

		
	
		#pragma omp sections
		{


			#pragma omp section
			{
				printf("Thread no %d executing addition operation\n",omp_get_thread_num());
				for(i=0;i<100;i++)
				{
					c[i]=a[i]+b[i];
				}
			}
			#pragma omp section
			{
				printf("Thread no %d executing multiplication operation\n",omp_get_thread_num());
				for(int i=0;i<100;i++)
				{
					d[i]=a[i]*b[i];
				}

			}

		}


	}






		
	
	for(int i=0;i<10;i++)
	{
	printf("%d	%d\n",c[i],d[i]);
	}

}
