#include<stdio.h>
#include<omp.h>
#define na 10
#define nb 20
#define nc 5

void disp(int x, int y, int a[][y]) {

for (int i=0; i<x; i++) {
		for (int j=0; j<y; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	
	double t1= omp_get_wtime();

	int a[na][nb], b[nb][nc], c[na][nc];
	#pragma omp parallel for shared(a,b,c)
	for (int i=0; i<na; i++) {
		for (int j=0; j<nb; j++) {
			a[i][j] = i+j;		
		}
	}
	#pragma omp parallel for shared(a,b,c)
	for (int i=0; i<nb; i++) {
		for (int j=0; j<nc; j++) {
			b[i][j] = i*j;		
		}
	}
	#pragma omp parallel for shared(a,b,c)
	for (int i=0; i<na; i++) {
		for (int j=0; j<nc; j++) {
			c[i][j] = 0;		
		}
	}


	printf("Matrix a\n");
	disp(na, nb, a);
	printf("Matrix b\n");
	disp(nb, nc, b);

	#pragma omp parallel for shared(a,b,c)
	for(int i=0; i<na; i++) {
		for(int j=0; j<nc; j++) {
			for(int k=0; k<nb; k++) {
				printf("c[%d][%d] calculated by %d\n", i,j, omp_get_thread_num());
				c[i][j] += a[i][k] + b[k][j];			
			}
		}
	}


	double t2 = omp_get_wtime();
	printf("Time taken %f\n", t2-t1);

	printf("Matrix c\n");
	disp(na, nc, c);
	


}

