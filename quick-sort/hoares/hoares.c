#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int partition(int* list, int low, int high);
void quickSort(int* list, int low, int high);
void swap(int* a, int* b);

int main(){
    int arr[] = {10,40,70,40,30,60,80,20,50};

    printf("before sort: ");
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, 8);

    printf("after sort: ");
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
}

void quickSort(int* list, int low, int high){
    if(low < high){
        int pivot = partition(list, low, high);

        quickSort(list, low, pivot); //
        quickSort(list, pivot+1, high);
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







int main(){

}
