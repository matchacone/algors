#include <stdio.h>

void gapSort(int* arr, int size);

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = 10;

    printf("Before sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    gapSort(arr,size);

    printf("\nAfter sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void gapSort(int* arr, int size){
    int gap = size/2;
    while(gap != 0){
        printf("gap: %d\n", gap);
        for(int i = gap; i<size; i++){
            int temp = arr[i];
            int j;
            for(j = i; j>=gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j-gap];
            }

            arr[j] = temp;
        }
        gap /= 2;
    }
}
