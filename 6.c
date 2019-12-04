#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

void main(){

	int max_p=INT_MIN;// INT_MIN  -> limits header file
	int max_s=INT_MIN;

	int i, a[100];

	for(i=0;i<100;i++)
		a[i]=rand()%1000;

	#pragma omp parallel num_threads(4)
	{

	for(i=0;i<100;i++){
		if(max_p<a[i]){
			#pragma omp critical
				max_p=a[i];		
		}
	
	}
		


	}

	for(i=0;i<100;i++){
		if(max_s<a[i]){
			max_s=a[i];		
		}
	
	}

	printf("Parallel max %d\n Serial max %d\n",max_p,max_s);
		



}
