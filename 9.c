#include<stdio.h>
#include<omp.h>

int main(){

    int s = 97;
    #pragma omp parallel for
    for(int i=s; i<s+26;i++){
        printf("%c - %d thread\n", i, omp_get_thread_num());
    }
}