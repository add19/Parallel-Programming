#include<time.h>
#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int n, m, i, j;
	printf("Enter the dimensions of the matrices:");
	scanf("%d", &n);

	int a[n][n], b[n][n], c[n][n];
	srand(time(NULL));

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i][j] = (rand()%10);
			b[i][j] = (rand()%10);
			c[i][j] = 0;
		}
	}
	
	#pragma omp parallel for private(m, j)
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				
				for(m=0; m<n; m++){
					c[i][j] = c[i][j] + a[i][m] * b[m][j];				
				}	
				printf("%d ", c[i][j]);		
			}
		}	
	
	return 0;
}
