#include <stdio.h>
#include <stdlib.h>

void combSort(int arr[], int n);

int main(){
    int arr[] = {7,8,4,3,1,2,7};
    int n = sizeof(arr) / sizeof(arr[0]);


    printf("Before sorting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    combSort(arr, n);

    printf("After sorting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void combSort(int arr[], int n){
    int gap = n;
    for(gap = n; gap > 0; gap = (gap) / 1.3) {
        for(int i = 0; i + gap < n; i++) {
            if(arr[i] > arr[i + gap]){ // bubble sort
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
        }
    }
}
