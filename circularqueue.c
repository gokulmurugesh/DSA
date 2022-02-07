#include<stdio.h>
int queue[5], front = 0, rear = -1, size = 0;
void enqueue(int x){
    if(size == 5){
        printf("Queue is Full");
    }else{
        rear = (rear+1)%5;
        queue[rear] = x;
        size++;
    }
}
void dequeue(){
    if(size == 0){
        printf("Queue is Empty");
    }else{
        front = (front+1)%5;
        size--;
    }
}
void display(){
    if(size == 0)
        printf("Queue is Empty");
    else{
        for(int i=front; i!=rear;i=(i+1)%5)
            printf("%d ",queue[i]);
        printf("%d ",queue[rear]);
    }
}
void main(){
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    enqueue(5);
    display();
}