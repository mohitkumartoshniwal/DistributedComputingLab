#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
		#pragma omp parallel num_threads(4)
		{
		
		int tid=omp_get_thread_num();
		if(tid==0)
		{
			int not=omp_get_num_threads();
			int nop=omp_get_num_procs();
			int mt=omp_get_max_threads();
			int ip=omp_in_parallel();
			int dy=omp_get_dynamic();
			int ne=omp_get_nested();

		printf("No of threads is %d\nNo of processors is %d\nMax threads %d\ndynamic threads enabled %d\n nested threads %d\nIn paralllel %d\n",not,nop,mt,dy,ne,ip); 

		}		

}

	

}
