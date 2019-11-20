#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void swap(int* a, int* b);
void quicksort(int* A, int p, int r);
int partitioning(int* A, int p, int r);

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
    quicksort(A, 0, dim-1);
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

void quicksort(int* A, int p, int r){
    if(p < r){
        int q = partitioning(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q+1, r);
    }
}

int partitioning(int* A, int p, int r){
    int pivot = A[p];
    int i = p-1;
    int j = r+1;
    do{
        do{
            j--;
        }while(A[j]>pivot);
        do{
            i++;
        }while(A[i]<pivot);
        if(i<j)
            swap(&A[i], &A[j]);
    }while (i<j);
    return j;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}