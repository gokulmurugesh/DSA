#include<stdio.h>
#include<stdlib.h>

struct node {
    int element;
    struct node *prev,*next;
}*head=NULL,*tail=NULL;

void insert(int x){
    struct node *new=malloc(sizeof(struct node));
    new->element = x;
    if(head == NULL && tail == NULL){
        head = new;
        head->prev = head;
        head->next = head;
        tail = head;
    }else{
        tail->next = new;
        new->prev = tail;
        new->next = head;
        tail = new;
    }
}

void delete(int x){
    struct node *temp = head;
    while(temp->next->element != x){
        temp = temp->next;
    }
    struct node *del=temp->next;
    temp->next->next->prev=temp;
    temp->next = temp->next->next;
}

void display(){
    struct node *temp=head;
    while(temp->next != head){
        printf("%d ",temp->element);
        temp = temp->next;
    }
    printf("%d ",temp->element);
}

void main(){
    insert(1);
    insert(2);
    insert(3);
    delete(2);
    display();
}