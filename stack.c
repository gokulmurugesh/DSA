#include<stdio.h>
// Stack - LIFO/FILO
int a[5], top=-1;
void insert(int x){
    if(top==sizeof(a)/sizeof(a[0]))
        printf("Stack is full.");
    else 
        a[++top] = x;
}
void delete(){
    if(top==-1)
        printf("Stack is empty.");
    else
        top--;
}
void print(){
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);
}
void main(){
    insert(1);
    insert(2);
    insert(3);
    delete();
    print();
}