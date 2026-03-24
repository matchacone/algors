#include <stdio.h>

void strandSort(int arr[], int n);

int main(){
    int arr[] = {6,5,4,3,2,2,1,7,8,10,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    strandSort(arr, n);
    
    printf("After sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void strandSort(int arr[], int n){
    int strandArr[n];
    int sortCount = 0;
    int strandCount = 0;
    while(sortCount != n){
        for(int i = 0; i < n; i++) {
            if(strandCount == 0 || arr[i] >= strandArr[strandCount - 1]) {
                strandArr[strandCount++] = arr[i];
            }
            else break;
        }
        
        while(strandCount != 0){
            for(int i = strandCount; i >= 0; i--) {
                arr[sortCount++] = strandArr[--strandCount];
            }
        }
        
    }
}