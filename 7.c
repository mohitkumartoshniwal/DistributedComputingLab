#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

void main(){

	omp_lock_t lock; //define a lock
	int max_p=INT_MIN;// INT_MIN  -> limits header file
	int max_s=INT_MIN;

	int i, a[100];

	for(i=0;i<100;i++)
		a[i]=rand()%1000;

	omp_init_lock(&lock);//initialize a lock

	#pragma omp parallel num_threads(4)
	{

	for(i=0;i<100;i++){
		if(max_p<a[i]){
			omp_set_lock(&lock);//set lock
				max_p=a[i];
			omp_unset_lock(&lock);//unset lock		
		}
	
	}
		


	}

	omp_destroy_lock(&lock);

	for(i=0;i<100;i++){
		if(max_s<a[i]){
			max_s=a[i];		
		}
	
	}

	printf("Parallel max %d\n Serial max %d\n",max_p,max_s);
		



}
