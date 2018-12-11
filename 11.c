#include<stdio.h>
#include<omp.h>

int main(){

    int x[4], psum[10], i ,j;

    #pragma omp parallel for lastprivate(x) private(j)
    for (int i=0; i<11; i++){
        x[0] = 1;
        for (j=1; j<4; j++){
            x[j] = x[j-1] * (i+1);
        }
        psum[i] = x[0]+x[1]+x[2]+x[3];


    }

    for (int i=0; i<11; i++){
        printf("%d -> %d\n", i, psum[i-1]);
    }

}