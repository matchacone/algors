#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} *node;

void insert(int data, node* BST);
void delete(int data, node* BST);
void inorder(node BST);

int main(){
    node root = NULL;

    // 1. Insert data
    printf("Inserting: 50, 30, 20, 40, 70, 60, 80\n");
    insert(50, &root);
    insert(30, &root);
    insert(20, &root);
    insert(40, &root);
    insert(70, &root);
    insert(60, &root);
    insert(80, &root);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n\n");

    // 2. Test Deleting a leaf
    printf("Deleting leaf (20)...\n");
    delete(20, &root);
    inorder(root);
    printf("\n\n");

    // 3. Test Deleting node with one child
    printf("Deleting node with one child (30)...\n");
    delete(30, &root);
    inorder(root);
    printf("\n\n");

    // 4. Test Deleting node with two children
    printf("Deleting root/two children (50)...\n");
    delete(50, &root);
    inorder(root);
    printf("\n\n");

    return 0;
}

void insert(int data, node* BST){

    node newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(*BST == NULL){
        *BST = newNode;
    }
    else{
        node* trav = BST;
        while(*trav != NULL && (*trav)->data != data){
            if(data > (*trav)->data) trav = &((*trav)->right);
            else trav = &((*trav)->left);
        }
        if(*trav == NULL) *trav = newNode;
    }
}

void delete(int data, node* BST){
    node* trav = BST;
    while(*trav != NULL && (*trav)->data != data){
        if(data > (*trav)->data) trav = &((*trav)->right);
        else trav = &((*trav)->left);
    }
    if(*trav != NULL){
        node toRemove = *trav;
        if((*trav)->right == NULL && (*trav)->left == NULL){ // no child
            *trav = NULL;
        }else if((*trav)->right != NULL && (*trav)->left == NULL){ // right child only
            *trav = (*trav)->right;
        }else if((*trav)->right == NULL && (*trav)->left != NULL){ // left child only
            *trav = (*trav)->left;
        }else{ // both child
            //grab right most predecessor or left most successor
            node* pred = &((*trav)->left);
            while((*pred)->right != NULL){
                pred = &((*pred)->right);
            }
            int predData = (*pred)->data;
            (*trav)->data = predData;
            
            toRemove = *pred;
            *pred = (*pred)->left;
        }
        free(toRemove);
    }
}

void inorder(node BST){
    if(BST != NULL){
        inorder(BST->left);
        printf("%d ", BST->data);
        inorder(BST->right);
    }
}