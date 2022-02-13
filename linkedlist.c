#include<stdio.h>
#include<stdlib.h>

//declaration of struct
struct node{
    int element;
    struct node *next; //recursive list tree - holds address of the next structure
}*head=NULL; //initial


void append(int x){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node)); // allocating memory for a struct.
    new->element = x;
    new->next = NULL;
    if(head == NULL)  // if the linked list is empty
        head = new;
    else{ // if the list contains elements
        struct node *temp = head;
        while(temp->next != NULL){ // Last element holds NULL 
            temp = temp->next; // moving forward.
        }
        temp->next = new;  //linking struct 'new' to temp->next(Recursive structure)
    }
}

void delete_last(){
    struct node *temp = head;
    while(temp->next->next != NULL){ //checking for NULL without going to the last struct
        temp = temp->next;
    }
    free(temp->next); //freeing the last struct
    temp->next = NULL; //initializing the last previous to NULL. so that it becomes the last 
}

void print(){
    if(head==NULL){
        printf("No Elements found"); //if the list is empty
        return;
    }else{
        struct node *temp=head;
        while(temp->next != NULL){ // checking for last element
            printf("%d ",temp->element); // printing the element
            temp = temp->next;  //moving forward or inside the recursion
        }
        printf("%d",temp->element); //printing the element
    }
    
}

void reverse(){
    struct node *prev=NULL,*next=NULL;
    while (head!=NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void main(){
    append(0);
    append(1);
    append(2);
    append(3);
    delete_last();
    delete_last();
    reverse();
    print();
}