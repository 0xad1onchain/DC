#include<stdio.h>
#include<omp.h>

int factorial(int n){
    int res = 1;
    for (int i=1; i<n+1; i++)
        res *= i;
    return res;
}

int main(){

    int size = 15;

    int fact[size];
    fact[0] = 1;
    for (int i=0;i<size;i++) fact[i]=factorial(i);
    int j=0;
    #pragma omp parallel for firstprivate(j, fact)
    for (int i=1; i<size; i++){
        j += i;
        fact[i] = j * fact[i-1];
    }

    for (int i=0; i<size; i++){
        printf("%d -> %d\n", i, fact[i]);
    }

}