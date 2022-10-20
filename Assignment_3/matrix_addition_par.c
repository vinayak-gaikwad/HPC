#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 2000

void matrixAdd(int** a, int** b, int** c){
    #pragma omp parallel for
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void initialiseMatrix(int** a, int num){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            a[i][j] = num;
        }
    }
}

void displayMatrix(int** a){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // int a[N][N], b[N][N], c[N][N];
    int** a;
    int** b;
    int** c;

    a = (int**)malloc(sizeof(int*) * N);
    b = (int**)malloc(sizeof(int*) * N);
    c = (int**)malloc(sizeof(int*) * N);

    for(int i=0; i<N; i++){
        a[i] = (int*)malloc(sizeof(int) * N);
        b[i] = (int*)malloc(sizeof(int) * N);
        c[i] = (int*)malloc(sizeof(int) * N);
    }


    initialiseMatrix(a, 1);
    initialiseMatrix(b, 1);
    omp_set_num_threads(8);
    double start; 
    double end; 
    start = omp_get_wtime();

    matrixAdd(a, b, c);
    end = omp_get_wtime(); 
    // t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC;

   
    //displayMatrix(c);
    printf("Time taken (seq): %f\n", end - start);
    
    free(a);
    free(b);
    free(c);
}