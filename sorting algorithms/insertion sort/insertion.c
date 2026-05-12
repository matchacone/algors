#include <stdio.h>

void insertionSort(int* arr, int size);
void swap(int* x, int* y);

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,10};
    int size = 10;

    printf("Before sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    insertionSort(arr,size);

    printf("\nAfter sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void insertionSort(int* arr, int size){
    for(int i = 1; i<size; i++){
       int val = arr[i];
       int prev = i-1;

       //shift to the right if low
       while(prev >= 0 && arr[prev] > val){
           arr[prev+1] = arr[prev];
           prev--;
       }

       arr[prev+1] = val;
    }
}
