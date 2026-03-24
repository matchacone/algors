#include <stdio.h>

void gnomeSort(int arr[], int n);

int main(){
    int arr[] = {5,3,4,2,5,1,2,6,8,7,10,9,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorted: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    gnomeSort(arr, n);

    printf("After sorted: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gnomeSort(int arr[], int n){
    int swap = 0;
    for(int i = 1; i<n; i++){
        int idx = i;
        swap = 0;
        for(; i>0 && arr[i] < arr[i-1]; i--){ // swap and move backwards
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            swap = 1;
        }
        i = idx; // some efficiency stuff to save time <3
    }
}
