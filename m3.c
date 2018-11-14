#include<stdio.h>
#include<omp.h>
#define max 10

void disp(int a[]) {
	for (int i=0; i<max; i++) {
		printf("%d \t", a[i]);
	}
	printf("\n");
}


int main() {

	int a[max], b[max], c[max];
	
	int i;
	for (int i=0; i<max; i++) {
		a[i] = i;
		b[i] = 2*i;
		c[i] = 0;
	}
	printf("Array a\n");
	disp(a);
	printf("Array b\n");
	disp(b);
	printf("Array c\n");
	disp(c);
	
	int sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for(int i=0; i<max; i++) {
		printf("%d operation is done by thread %d\n", i, omp_get_thread_num());
		sum += a[i] + b[i];
	}

	printf("Array c\n");
	disp(c);

	printf("Sum: %d\n", sum);
}


