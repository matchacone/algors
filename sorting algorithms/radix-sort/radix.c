#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BASE 10

typedef struct node{
    int num;
    struct node* next;
}*List;

typedef struct {
    List buckets[BASE];
} Buckets;

void radixSort(int arr[], int n);

int main(){

    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Before sort: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    radixSort(array, n);

    printf("After sort: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void radixSort(int arr[], int n) {
    int maxDig = 0;
    for(int i = 0; i<n; i++){ // get max dig
        int dig = 0;
        int ref = arr[i];
        while(ref != 0){
            dig++;
            ref /= 10;
        }
        if(dig > maxDig) maxDig = dig;
    }

    Buckets buckets;
    for(int i = 0; i<BASE; i++){ // init to NULL
        buckets.buckets[i] = NULL;
    }

    for(int i = 1; i<=maxDig; i++){
        int place = 1;

        if(i != 1){
            for(int j = 1; j<i; j++) place *= 10;       // digit to be placed in bucket
        }

        for(int j = 0; j<n; j++){                       // store in buckets
            int idx = arr[j] / place % BASE;            // formula for getting digit

            List newNode = malloc(sizeof(struct node)); // create new node
            newNode->num = arr[j];
            newNode->next = NULL;

            List* trav;                 // insert last
            for(trav = &buckets.buckets[idx]; *trav != NULL; trav = &(*trav)->next){}

            newNode->next = *trav;
            *trav = newNode;
        }

        int arrCount = 0;
        for(int j = 0; j<BASE; j++){ // replace arr elements with the elements in buckets
            List* trav = &buckets.buckets[j];
            while(*trav != NULL){
                List temp = *trav;
                arr[arrCount++] = temp->num;
                *trav = temp->next;
                free(temp);
            }
        }

        for(int i = 0; i<n; i++) printf("%d ", arr[i]);
        printf("\n");
    }

}
