#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arras[], int length){
    int value;
    int empty;
    for(int i=1; i<length; i++){
        value = arras[i];
        empty = i;
        while(empty>0 && arras[empty-1] > value){
            arras[empty] = arras[empty-1];
            --empty;
        }
        arras[empty] = value;
    }
}

int main(){
    int arra[] = {2,5,7,3,4,1,6};
    int length = 7;
    cout<<"Array before sorting: ";
    for(int i=0; i<length; i++){
        cout<<arra[i]<<" ";
    }
    cout<<"\nArray after  sorting: ";
    insertionSort(arra, length);
    for(int i=0; i<length; i++){
        cout<<arra[i]<<" ";
    }
}