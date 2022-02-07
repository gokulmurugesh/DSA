#include<stdio.h>
#include<stdlib.h>

struct node {
    int element;
    struct node *left,*right;
};

struct node * newNode(int x){
    struct node *temp = malloc(sizeof(struct node));
    temp->element=x;
    temp->left=temp->right=NULL;
    return temp;
}

struct node * insert(struct node *node, int x){
    if(node==NULL)
        return newNode(x);
    else if(x < node->element)
        node->left = insert(node->left,x);
    else
        node->right = insert(node->right,x);
    return node;
}

void display(struct node *node){
    if(node!=NULL){
     	display(node->left);
		printf("%d \n", node->element);
		display(node->right);
    }
}

void main(){
    struct node *root=NULL;
    root = insert(root,1);
    insert(root,5);
    insert(root,6);
    display(root);
}
