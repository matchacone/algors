#include <stdio.h>
#include <stdlib.h>
#define BASE 10

typedef struct node{
    int num;
    struct node *next;
} *List;

typedef List bucket[10];

void bucketSort(int arr[], int n);

int main(){
    //int arr[] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95}; //perfectly distributed array
    int arr[] = {42, 49, 41, 15, 12, 45, 99, 91, 0, 7}; // collision testing
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Before sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    bucketSort(arr, size);

    printf("\nAfter sort: ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

}

void bucketSort(int arr[], int n){
    bucket myBucket;
    for(int i = 0; i<BASE; i++){    // init buckets
        myBucket[i] = NULL;
    }

        for(int i = 0; i<n; i++){
            int idx;
            idx= arr[i]/BASE;
            List newNode = malloc(sizeof(struct node));
            if(newNode != NULL){
                newNode->num = arr[i];
                newNode->next = NULL;

                List* trav;
                for(trav = &myBucket[idx]; *trav != NULL && newNode->num > (*trav)->num; trav = &(*trav)->next){} // insert sorted
                newNode->next = *trav;
                *trav = newNode;
            }
        }

        int arrCount = 0;
        for(int i = 0; i<BASE; i++){ // transfer from bucket to array
            List* trav = &myBucket[i];
            while(*trav != NULL){
                List temp = *trav;
                arr[arrCount++] = temp->num;
                *trav = temp->next;
                free(temp);
            }
        }

}
