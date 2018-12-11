#include<stdio.h>
#include<omp.h>

int main(){

    int p, q;

    printf("Enter dimmensions of matrix\n");
    scanf("%d%d", &p, &q);

    int mat[p][q];
    int vec[p];

    printf("Enter elements in matrix\n");
    for (int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Matrix is\n");
    for (int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter elements in vector\n");
    for (int i=0; i<p; i++){ 
        scanf("%d", &vec[i]);
    }
    printf("Vector is \n");
    for (int i=0; i<p; i++){
        printf("%d\t", vec[i]);
    }
    printf("\n");

    int res[q];
    for (int i=0; i<q; i++){
        res[i] = 0;
    }

    #pragma omp parallel for
    for (int i=0; i<q; i++){
        for (int j=0; j<p; j++){
            printf("%d * %d by thread %d\n", vec[j], mat[j][i], omp_get_thread_num());
            res[i] += vec[j] * mat[j][i];
        }

    }

    printf("Result is \n");

    for (int i=0; i<q; i++){
        printf("%d\t", res[i]);
    }
    printf("\n");




}