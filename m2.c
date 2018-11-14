#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
//ADDED COMMENTS
#define ARR_SIZE 10000000
int a[ARR_SIZE];
double t1,t2;
int main(int *argc,char *argv[]){
  for(int i=0;i<ARR_SIZE;i++) {
    a[i] = 1;
  }
  int sum = 0;
  double t1;
  double t2;
  int num_threads;
  t1 = omp_get_wtime();
  #pragma omp parallel
  {
    //COMPUTE SUM OF ARRAY USING CRITICAL section
    //PSUM IS PRIVATE TO EACH THREAD HENCE NO PROBLEM HOWEVER SUM IS GLOBAL AND HENCE MAY LEAD TO RACE CONDITIONS SO IT IS UPDATED IN CRITICAL SECTION
    int psum = 0;

    #pragma omp for
    for(int i = 0; i<ARR_SIZE; i++)
      psum += a[i];
    #pragma omp critical
    sum += psum;
  }
  t2 = omp_get_wtime();
  printf("%d\n",sum);
  printf("Time taken is %f",t2-t1);
  return 0;
}
