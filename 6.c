#include<stdio.h>
#include<omp.h>
#define SIZE 100000

int main(){
    int arr[SIZE];
    int i, j;

    srand(90);

    for (i=0; i<SIZE; i++){
        arr[i] = rand();
        //printf("%d\t");
    }
    printf("\n");

    int max = 0;

    #pragma omp parallel for 
    for (i = 0; i < SIZE; i++)
    {
        //#pragma omp critical
        if (arr[i] > max)
            max = arr[i]; 
        //printf("%d element done by %d thread\n", i, omp_get_thread_num());  
    }

    int serial_max = 0;
    for (i=0; i<SIZE; i++){
        if (arr[i]>serial_max)
            serial_max = arr[i];
    }

    printf("Parallel Max %d Serial Max %d\n", max, serial_max);

    return 0;
    

}