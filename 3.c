#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
	int a[1000],b[1000],c[1000],i,sum=0;

	for(i=0;i<1000;i++)
	{

		a[i]=b[i]=i;
	}

	#pragma omp parallel for reduction(+:sum)//if "for" is not used then braces can be used
	for(i=0;i<1000;i++){//otherwise do it  like here 
		sum=sum+a[i]+b[i];
		c[i]=sum;

	}		


	

	for(int i=0;i<10;i++)
	{
	printf("%d\n",c[i]);
	}


}
