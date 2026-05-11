#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list* next;
} *List;

void strandSort(List* ref);

void insertLast(List* ref, int val);
void insertSorted(List* ref, int val);
void deleteNode(List* ref, int val);

void printList(List ref);

int main(){
    List head = NULL;
    insertLast(&head, 5);
    insertLast(&head, 3);
    insertLast(&head, 8);
    insertLast(&head, 1);
    insertLast(&head, 5);
    insertLast(&head, 4);
    insertLast(&head, 6);
    insertLast(&head, 7);
    insertLast(&head, 2);
    insertLast(&head, 3);
    insertLast(&head, 9);

    printf("Before sort: ");
    printList(head);

    strandSort(&head);

    printf("After sort: ");
    printList(head);
}

void strandSort(List* ref){
    if(*ref != NULL){
        List substrand = NULL;
        List sorted = NULL;

        while(*ref != NULL){
            for(List* trav = ref; *trav != NULL; trav = &(*trav)->next){
                if(substrand == NULL || (*trav)->val <= substrand->val){
                    insertLast(&substrand, (*trav)->val);
                    deleteNode(ref, (*trav)->val);
                }
                else break;
            }
            for(List* trav = &substrand; (*trav) != NULL; trav = &(*trav)->next){
                insertSorted(&sorted, (*trav)->val);
                deleteNode(&substrand, (*trav)->val);
            }
        }
        *ref = sorted;
    }
}


void printList(List ref){
    for(List trav = ref; trav != NULL; trav = trav->next){
        printf("%d ", trav->val);
    }
    printf("\n");
}


void insertLast(List* ref, int val){
    List newNode = malloc(sizeof(struct list));
    if(newNode != NULL){
        newNode->val = val;
        newNode->next = NULL;

        List* trav;
        for(trav = ref; *trav != NULL; trav = &(*trav)->next){}
        *trav = newNode;
    }
}

void insertSorted(List* ref, int val){
    List newNode = malloc(sizeof(struct list));
    if(newNode != NULL){
        newNode->val = val;
        newNode->next = NULL;

        List* trav;
        for(trav = ref; *trav != NULL && (*trav)->val <= val; trav = &(*trav)->next){}
        newNode->next = *trav;
        *trav = newNode;
    }
}

void deleteNode(List* ref, int val){
    List* trav;
    for(trav = ref; *trav != NULL && (*trav)->val != val; trav = &(*trav)->next){}
    if(*trav != NULL){
        List temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}
