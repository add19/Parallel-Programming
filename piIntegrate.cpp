#include<bits/stdc++.h>
#include<omp.h>
#include<cstdlib>
using namespace std;

long steps = 1000000000;//total number of strips
int main(){
	
	int i;//for iterating through the number of strips
	double x, start, end, pi; 
	double sum = 0.0;//initialize per quarter

	double step = 1.0 / steps;//width of each strip

	start = omp_get_wtime();
	#pragma omp parallel for private(x) reduction(+:sum) //for preserving integrity of x and sum in using multiple threads
	for(i=0; i<steps; i++){
		x = (i + 0.5) * step;
		sum = sum + 4.0/(1.0 + x * x);
	}

	pi = step * sum; //total values
	end = omp_get_wtime();

	cout.precision(5);
	 cout << "Pi= " << pi << " Time elapsed: " << end - start << endl; //total time for evaluating pi value

	return 0;
}