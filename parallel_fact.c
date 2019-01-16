#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int factorial(int i){
	if(i == 1 || i == 0){
		return 1;	
	}else{
		return i * factorial(i - 1);
	}
}
