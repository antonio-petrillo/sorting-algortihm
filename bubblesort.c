#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void bubblesort(int* A, int dim);
void swap(int* a, int* b);

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
    bubblesort(A, dim);
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

void bubblesort(int* A, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim-i-1; j++){
            if(A[j]>A[j+1]) swap(&A[j], &A[j+1]);
        }
    }
    return;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}