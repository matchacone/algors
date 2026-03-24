#include <stdio.h>

void bubbleSort(int* arr, int size);

int main(){
    int arr[] = {9,8,7,6,5,4,3,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

        printf("Before sort: ");
        for(int i = 0; i<size; i++){
            printf("%d ", arr[i]);
        }

        bubbleSort(arr,size);

        printf("\nAfter sort: ");
        for(int i = 0; i<size; i++){
            printf("%d ", arr[i]);
        }
}

void bubbleSort(int* arr, int size){
    int swapped;
    for(int i = 0; i<size; i++){
        swapped = 0;
        for(int j = 0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}
