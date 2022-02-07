#include<stdio.h>

int main(){
    int a[5]={1,2,3,4,5}, x=5, start=0,end=4, search;
    while(start <= end){
        search = (start+end)/2;
        if(a[search] == x){
            printf("Found at %d",search);
            return 0;
        }else if(x < a[search]){
            end = search-1;
        }else{
            start = search+1;
        }
    }
    printf("Not Found");
    return 0;
}