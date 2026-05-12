#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define INF 99999
typedef struct POT{
    int arr[SIZE];
    int capacity;
}heap;

void onlineTourna(heap* ref);

int main(){
    int unsortedData[] = {45, 12, 85, 32, 7, 60, 99, 1, 55, 20};

    heap myHeap;
    myHeap.capacity = 0;

    for(int i = 0; i < SIZE; i++) {
            // 1. Add the new arrival to the end of the array
            myHeap.arr[myHeap.capacity] = unsortedData[i];
            myHeap.capacity++;
    }

    printf("Before sort: ");
    for(int i = 0; i<SIZE; i++) printf("%d ", myHeap.arr[i]);

    for(int i = 0; i<SIZE; i++){
        onlineTourna(&myHeap);
    }

    printf("\nAfter sort: ");
    for(int i = 0; i<SIZE; i++) printf("%d ", myHeap.arr[i]);

}

void onlineTourna(heap* ref){
    int tournamentHeap[7];
    int sortedBuffer[SIZE];
    for(int i = 0; i<7; i++){
        tournamentHeap[i] = INF;
    }
    int bufferCount = 0;
    int refCount = 0;
    while(bufferCount != ref->capacity){
        for(int i = 3; i<7; i++){ // insert
            if(tournamentHeap[i] == INF) tournamentHeap[i] = ref->arr[refCount++];
        }

        for(int i = 0; i<7; i++){
            int parent = i;
            int LChild = 2 * i + 1;
            int RChild = 2 * i + 2;

            if(LChild < 7 && RChild < 7){
                tournamentHeap[parent] = (LChild < RChild) ? tournamentHeap[LChild] : tournamentHeap[RChild];
            }
        }


    }


}
