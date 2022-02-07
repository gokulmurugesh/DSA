//Simple Queue - FIFO/LILO
#include<stdio.h>
int a[5], front=0, rear=-1;
void insert(int x){
    if(rear==sizeof(a)/sizeof(a[0]))
        printf("Queue is full.");
    else 
        a[++rear] = x;
}
void delete(){
    if(rear==-1)
        printf("Queue is empty.");
    else
        front++;
}
void print(){
    for(int i=front;i<=rear;i++)
        printf("%d ",a[i]);
}
void main(){
    insert(1);
    insert(2);
    insert(3);
    delete();
    print();
}