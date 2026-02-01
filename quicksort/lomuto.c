#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int partition(int* list, int low, int high);
void quickSort(int* list, int low, int high);


int main(){
    int arr[] = {5,7,4,3,6,8,9,1,2,10};

    printf("before sort: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, 9);


}

void quickSort(int* list, int low, int high){
    if(low < high){ // partition array and get pivot
        int pivot = partition(list, low, high);

        quickSort(list, low, pivot - 1); // sort low sub-array
        quickSort(list, pivot + 1, high); // sort high sub-array
    }
}

int partition(int* list, int low, int high){
    int pivot = list[high];
    int i = low - 1;


}


