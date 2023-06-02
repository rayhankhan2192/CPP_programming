#include<stdio.h>
int main(){
    int A[50]={1,2,3,32,45,22,24,31,43,21,18,20,16,47,38,11,49,34};
    int i,value,pos=0;
    printf("Enter the value to search= ");
    scanf("%d",&value);
    for(i=0; i<50;i++){
        if(value==A[i]){
            pos=i+1;
        }
    }
    if(pos==0){
        printf("Value not found");
    }
    else{
        printf("Value is available\n");
        printf("Position is %d",pos);
    }
}