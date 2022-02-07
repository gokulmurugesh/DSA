#include<stdio.h>
#include<stdlib.h>
struct node {
    int element;
    struct node *next;
}*head=NULL;

void insert(int x){
    struct node *new=malloc(sizeof(struct node));
    new->element = x;
    if(head==NULL){
        head=new;
        head->next = head;
    }else{
        new->next=head;
        struct node *temp=head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next=new;
    }
}
void delete(int x){
    struct node *temp=head;
    while(temp->next->element != x){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next = temp->next->next;
    free(del);
}
void display(){
    struct node *temp=head;
    while(temp->next != head){
        printf("%d ",temp->element);
        temp=temp->next;
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