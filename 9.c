#include<omp.h>
#include<stdio.h>

void main(){

	#pragma omp parallel for ordered//note the "for" and "ordered"
	for(int i=97;i<=122;i++)
	#pragma omp ordered
	printf("%c",i);
	
	printf("\n");


}
