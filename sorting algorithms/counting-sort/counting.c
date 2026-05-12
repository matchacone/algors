//simple version (unstable) time: o(n+k), space; o(n+m)

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n);

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
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
    int max = arr[0];
    int* countArr;
    for(int i = 1; i<n; i++){ // step 1. find the max value;
        if(arr[i] > max){
            max = arr[i];
        }
    }

    countArr = (int*)calloc(max+1, sizeof(int)); // step 2. allocate memory for count array

    for(int i = 0; i<n; i++){ // step 3. count the frequency of each element
        countArr[arr[i]]++;
        //printf("%d\n", arr[i]);
    }
    int sortedArr[n];

    int count = 0;
    for(int i = 0; i<max+1; i++){ // step 4. iterate thru the count array
        while(countArr[i] > 0){
            sortedArr[count++] = i;
            countArr[i]--;
        }
    }

    for(int i = 0; i<n; i++){ // step 5. return the elements from the sorted array to the original array
        arr[i] = sortedArr[i];
    }
}
