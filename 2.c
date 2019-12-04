#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
	int a[100];
	int sum=0,i;

	for(i=0;i<100;i++){
	a[i]=i;
	}

	#pragma omp parallel num_threads(8)
	{	
		int temp=0;

		#pragma omp for
		for(i=0;i<100;i++)
			temp+=a[i];
		#pragma omp critical
			sum+=temp;
	


	}

	printf("Total sum is %d\n",sum);


		









}
