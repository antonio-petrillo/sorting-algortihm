#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void dump(int* A, int dim);
void swap(int* a, int* b);
void heapsort(int* A, int dim);
void buildheap(int* A, int dim);
void heapify(int* A, int sub,int dim);

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
    heapsort(A, dim);
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

void dump(int* A, int dim){
    for(int i=0; i<dim; i++)
        (i%18 == 0) ? printf("\n%4d", A[i]): printf("%4d", A[i]);
    puts("\n");
    return;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;    
}

void heapsort(int* A, int dim){
    buildheap(A, dim);
    for(int i=dim-1; i>0; i--){
        swap(&A[0], &A[i]);
        heapify(A, 0, i);
    }
    return;
}

void buildheap(int* A, int dim){
   for(int i=dim/2-1; i>=0; i--)
       heapify(A, i, dim);
    return;
}

void heapify(int* A, int sub,int dim){
    int max;
    int l = 2*sub+1;
    int r = 2*sub+2;
    if(l < dim && A[l]>A[sub])
        max = l;
    else
        max = sub;
    if(r < dim && A[r]>A[max])
        max = r;
    if(max != sub){
        swap(&A[max], &A[sub]);
        //dump(A, dim);
        heapify(A, max, dim);
    }
    return;    
}
















