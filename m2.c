#include<stdio.h>
#include<omp.h>
#define max 1000000

int main() {
	int a[max];
	int sum = 0;

	for(int i=0; i<max; i++) {
		a[i] = 1;
	}	

	#pragma omp parallel
	{
	
		int psum = 0;
		
		#pragma omp for
		for(int i=0; i<max; i++) {
			psum += a[i];
		}
		#pragma omp critical
		sum += psum;
	
	}

	printf("Sum: %d\n", sum);
	
}
