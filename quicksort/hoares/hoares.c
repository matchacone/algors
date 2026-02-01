#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int partition(int* list, int low, int high);
void quickSort(int* list, int low, int high);
void swap(int* a, int* b);

int main(){
    int arr[] = {5,7,4,3,6,8,9,1,2,10};

    printf("before sort: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, 9);

    printf("after sort: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
}

void quickSort(int* list, int low, int high){
    if(low < high){
        int pivot = partition(list, low, high);

        quickSort(list, low, pivot);
        quickSort(list, pivot + 1, high);
    }
}

int partition(int* list, int low, int high){
    int pivot = list[(high+low)/2]; // take middle element as the pivot

    int i = low - 1;
    int j = high + 1;
    
    while(1){
        while(i < high && list[++i] < pivot);
        while(j > low && list[--j] > pivot);
        if(i >= j) return j;
        swap(&list[i], &list[j]);
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


