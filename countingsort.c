#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void countingsort(int* A, int dim);

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
    countingsort(A, dim);
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

void countingsort(int* A, int dim){
    int max = A[0];
    for(int i=1; i<dim; i++)
        if(A[i] > max) max = A[i];
    int* v = (int*)calloc(max+1, sizeof(int));
    if(!v){printf("errore\n"); exit(0);}
    for(int i=0; i<dim; i++)
        v[A[i]]++;
    int* ord = (int*) calloc(dim, sizeof(int));
    if(!ord){printf("errore\n"); exit(0);}
    for(int i=1; i<=max;i++)
        v[i]+= v[i-1];
    for(int i=dim-1; i>=0; i--){
        ord[v[A[i]]-1] = A[i];
        v[A[i]]--;
    }
    for(int i=0; i<dim; i++)
        A[i] = ord[i];
}