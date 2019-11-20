#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void inserctionsort(int* A, int dim);

int main(int argc, char** argv){
    randomize;
    int dim = atoi(argv[1]);
    int max = atoi(argv[2]);
    int* A = (int*) calloc(dim, sizeof(int));
    if(!A){
        printf("errore\n");
        exit(0);
    }
    for(int i=0; i<dim; i++){
        A[i] = random(max);
    }
    clock_t start = clock();
    inserctionsort(A, dim);
    clock_t end = clock();
    for(int i=0; i<dim-1; i++){
        if(A[i] > A[i+1]){
            printf("the algorithm doesn't work! idiot!\n");
            exit(0);
        }
    }
    printf("the algorithm work!\n");
    printf("tempo di esecuzione: %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
    free(A);
    return 0;
}

void inserctionsort(int* A, int dim){
    for(int i=1; i<dim; i++){
        int tmp = A[i];
        int j = i-1;
        while(j>=0 && tmp < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
    }
    return;
}