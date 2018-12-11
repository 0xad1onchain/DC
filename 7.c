#include<stdio.h>
#include<omp.h>
#define SIZE 1000

int main(){
    omp_lock_t lock;
    int arr[SIZE], i, max = 0, serial_max = 0;

    srand(100);
    omp_init_lock(&lock);

    for(int i=0; i<SIZE; i++){
        arr[i] = rand();
    }

    double t1 = omp_get_wtime();

    #pragma omp parallel for
    for(i=0; i<SIZE; i++){
        printf("%d element computed by %d thread\n", i, omp_get_thread_num());
       
        if(arr[i]>max){
            omp_set_lock(&lock);
            max = arr[i];
            omp_unset_lock(&lock);
        }
    }

    omp_destroy_lock(&lock);

    double t2 = omp_get_wtime();

    double t3 = omp_get_wtime();

   
    for(i=0; i<SIZE; i++){
       

        if(arr[i]>serial_max){

            serial_max = arr[i];

        }
    }

    double t4 = omp_get_wtime();

    printf("%d max in %f Parallel time, %d max in %f serial time\n", max, t2-t1, serial_max, t4-t3);
}