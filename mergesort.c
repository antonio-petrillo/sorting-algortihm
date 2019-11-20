#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randomize srand(time(NULL))
#define random(x) rand()%x

void mergesort(int* A, int p, int r);
void merge(int* A, int p, int q, int r);

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
    mergesort(A, 0, dim);
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

void mergesort(int* A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
    return;
}

void merge(int* A, int p, int q, int r){
    int* left, *right;
    int index1 = q-p+1;
    int index2 = r-q;
    left = (int*)calloc(index1, sizeof(int));
    right = (int*)calloc(index2, sizeof(int));
    for(int i=0; i<index1; i++)
        left[i] = A[p+i];
    for(int i=0; i<index2; i++)
        right[i] = A[q+1+i];
    int i=0, j=0, k=p;
    while(i<index1 && j<index2){
        if(left[i]<=right[j]){
            A[k] = left[i];
            i++;
        }
        else{
            A[k] = right[j];
            j++;
        }
        k++;        
    }
    while(i<index1){
        A[k] = left[i];
        i++;
        k++;
    }
    while(j<index2){
        A[k] = right[j];
        j++;
        k++;
    }
    free(left);
    free(right);
    return;
}