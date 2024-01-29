#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int data;
    struct Tree* right;
    struct Tree* left;
};
struct Tree* createTreeitem(int data){
    struct Tree* newItem=(struct Tree*) malloc(sizeof(struct Tree*));
    if(newItem!=NULL) {
        newItem->data = data;
        newItem->right = NULL;
        newItem->left = NULL;
    }
    return newItem;
}

void detsroy(struct Tree* leaf){
    if(leaf!=NULL){
        detsroy(leaf->left);
        detsroy(leaf->right);
        free(leaf);
    }
}

void inorder(struct Tree* p){
    if (p!=NULL){
        inorder(p->left);
        printf("%d  ",p->data);
        inorder(p->right);
    }
}
void preorder(struct Tree* root){
    if(root!=NULL){
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Tree* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}
int main() {
    struct Tree* root=createTreeitem(60);
    root->left= createTreeitem(20);
    root->left->left= createTreeitem(10);
    root->left->right= createTreeitem(40);
    root->left->right->left= createTreeitem(30);
    root->left->right->right= createTreeitem(50);
    root->right= createTreeitem(70);

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    return 0;
}