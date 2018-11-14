#include<stdio.h>
#include<omp.h>
#define n 10

void disp(int a[]) {
	for (int i=0; i<n; i++) {
		printf("%d \t", a[i]);
	}
	printf("\n");
}

int main() {

	int i, num, id,j;
	int a[n], b[n], c[n], d[n];
	
	//Array init
	for(i=0; i<n; i++) {
		a[i] = i;
		b[i] = 2*i + 22;
		c[i] = d[i] = 0;	
	}

	printf("array a and b\n");
	disp(a);
	disp(b);
	

	#pragma omp parallel sections num_threads(2)
	{
		
		#pragma omp section
		{
			for (i=0; i<n; i++) {
				c[i] = a[i] + b[i];
				printf("c[%d] done by %d thread\n",i, omp_get_thread_num());
			}
		}

		#pragma omp section
		{
			for(j=0; j<n; j++) {
				d[j] = a[j] * b[j];
				printf("d[%d] done by %d thread\n",j, omp_get_thread_num());
			}
		}
	}

	printf("Array c and d\n");
	disp(c);
	disp(d);
}

