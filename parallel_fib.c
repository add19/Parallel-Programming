#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

long long fib_value[1000];


long long fib(long i){
	if(i == 0 || i == 1){
		return 1;
	}else{
		if(fib_value[i] != 0){
			return fib_value[i];
		}
		else{
			fib_value[i] = fib(i - 1) + fib(i - 2); 
			return fib_value[i];	
		}
	}
}


int main(){
	
	long long n=50;

	double start, end;
	long long i=0;

	// omp_set_num_threads(4);

	start = omp_get_wtime();
	#pragma omp parallel for private(i)
		for(i=0; i<n; i++){
			printf("Fib[%lld] = %lld\n", i, fib(i));
		}	
	end = omp_get_wtime();

	printf("Work took %f sec. time.\n", end-start);
	return 0;
}
