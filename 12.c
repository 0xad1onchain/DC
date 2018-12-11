#include<stdio.h>
#include<omp.h>

int main(){

    int n = 81920, count = 0;

    double t1 = omp_get_wtime();

    #pragma omp parallel for
    for (int i=2; i<n; i++){
        int f = 1;
        for(int j=2; j<i; j++){
            if (i%j==0)
                f = 0;
        }
        if (f)
            #pragma omp critical
            count ++;
    }

    double t2 = omp_get_wtime();

    printf("%d primes found in 0 - %d in %f s\n", count, n, t2-t1);
}