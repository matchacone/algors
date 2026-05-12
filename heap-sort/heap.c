#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct POT{
    int arr[SIZE];
    int capacity;
}POT;

void initPOT(POT* ref){
    ref->capacity = 0;
}

void heapSort(POT* ref);
void heapify(POT* ref);
void insertHeap(POT* ref, int elem);

int main(){
    int worstCase[] ={10, 20, 30, 40, 50, 60, 70,80,90,100};
    int bestCase[] = {100, 80, 60, 40, 20, 10, 5,4,3,2};
    int dupes[] = {50, 10, 50, 20, 10, 50, 30,30,20,40};

    POT myPOT;
    initPOT(&myPOT);

    for(int i = 0; i<SIZE; i++){
        myPOT.arr[i] = worstCase[i];
        //myPOT.arr[i] = bestCase[i];
        //myPOT.arr[i] = dupes[i];
        myPOT.capacity++;
    }

    printf("Before sort: ");
    for(int i = 0; i<SIZE; i++){
        printf("%d ", myPOT.arr[i]);
    }

    heapSort(&myPOT);

    printf("\nAfter sort: ");
    for(int i = 0; i<SIZE; i++){
        printf("%d ", myPOT.arr[i]);
    }

}
