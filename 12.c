#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

void findprime(int n){

double t1,t2;
int p,i;
bool prime[n+1];//stdbool.h
memset(prime,true,sizeof(prime));//string.h

t1=omp_get_wtime();//remember

#pragma omp parallel num_threads(8)
for(p=2;p<=n;p++){
	if(prime[p]){
		for(i=p*p;i<=n;i+=p){
			prime[i]=false;	//stdbool.h	
		}
	}
}

t2=omp_get_wtime();

int tot=0;

printf("Time taken is %0.6f\n",t2-t1);
printf("Prime numbers are\n");
for(p=2;p<=n;p++){
	if(prime[p]){
		printf("%d   ",p);
		tot++;
	}
}
printf("\nHence total number of prime numbers %d\n",tot);

}


void main(){

int n;
printf("Enter no\n");
scanf("%d",&n);
findprime(n);

}
