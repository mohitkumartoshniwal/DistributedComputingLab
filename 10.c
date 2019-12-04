#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main() {

	long long fact1=1,fact2=1,i;
	int n;
	printf("Enter no\n");
	scanf("%d",&n);

	#pragma omp parallel for firstprivate(n) num_threads(4)
	for(i=2;i<=n;i++)
	fact1=fact1*i;

	#pragma omp parallel for firstprivate(n,fact2) num_threads(4)
	for(i=2;i<=n;i++)
	fact2=fact2*i;

	printf("factorial without using firstprivate is %llu and using firstprivate is %llu\n",fact1,fact2); 



}
