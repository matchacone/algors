#include <stdio.h>

void selectionSort(int arr[], int n);

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorted: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    selectionSort(arr, n);
    printf("\nAfter sorted: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int idx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[idx]){
                idx = j;
            }
        }
        if(idx != i){
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
    }
}
