//cumulative counting sort (stable) time: o(n+k), space: o(n+m)

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n);

int main(){
    int arr[] = {4,2,1,4,8,9,7,5,6,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorted: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("After sorted: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int arr[], int n){
    int* countArr;

    int max = arr[0];
    int min = arr[0];

    for(int i = 0; i<n; i++){ // find the range of values
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }

    int range = max - min + 1;
    countArr = (int*)calloc(range, sizeof(int)); // get the range of values and allocate memory for the count array

    for(int i = 0; i<n; i++){ // get the frequency of each element in the original array
        int idx = arr[i] - min;
        countArr[idx]++;
    }

    for(int i = 1; i<range; i++){ // calculate cumulative sum
        countArr[i] += countArr[i-1];
    }

    int sortedArr[n];
    for(int i = n-1; i>= 0; i--){
        int idx = arr[i] - min;
        sortedArr[countArr[idx] - 1] = arr[i];
        countArr[idx]--; // incase of duplicates, next to it
    }

    for(int i = 0; i<n; i++){
        arr[i] = sortedArr[i];
    }
}
