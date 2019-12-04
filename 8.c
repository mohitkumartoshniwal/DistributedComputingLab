#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
		int m,n,i,j;
	printf("Enter the size of the matrix\n");
	scanf("%d %d",&m,&n);
	printf("Matrix is of size %d * %d. Initialising matrix and vector of size %d * 1 with random values\n",m,n,n);
	int mat[m][n], vec[n], res[m];
	for(i = 0; i<m; i++)
	 {
	    for(j = 0; j<n; j++) 	
		{
	            mat[i][j] = rand()%100;
        	}
	        res[i] = 0;
    	}
        for(i = 0; i<n; i++)
        vec[i] = rand()%100;
    
    	printf("Matrix\n");
    	for(i = 0; i<m; i++) {
    	    for(j = 0; j<n; j++) {
    	        printf("%d ",mat[i][j]);
    	    }
    	    printf("\n");
    	}
    	printf("Vector\n");
    	for(i = 0; i<n; i++)
    	    printf("%d\n",vec[i]);
	
	#pragma omp parallel for num_threads(4)
	for(i=0;i<m;i++){
	printf("Execution of %d row done by %d\n",i,omp_get_thread_num());
	for(j=0;j<n;j++)
		 res[i] = res[i] + mat[i][j] * vec[j];
    
	}
	
	printf("Result is\n");
	for(i=0;i<m;i++){
	printf("%d ",res[i]);
	
	}
	printf("\n");
		


					
		






}
