#include<stdio.h>
#include<omp.h>

int main() {

	#pragma omp parallel
	{
	int tid = omp_get_thread_num();
	if (tid == 0) {
		printf("System threads %d\n", omp_get_num_threads());
		printf("System procs %d\n", omp_get_num_procs());
		printf("System tmaxt %d\n", omp_get_max_threads());
		printf("System in parallel %d\n", omp_in_parallel());
		printf("System dynamic %d\n", omp_get_dynamic());
		printf("System nested %d\n", omp_get_nested());	
	}
	}
}
