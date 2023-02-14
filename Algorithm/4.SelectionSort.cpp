#include<iostream>
using namespace std;

void selectionSort(int arrs[], int length){
    for(int i=0; i<length; i++){
        int min_index = i;
        for(int j=i+1; j<length; j++){
            if(arrs[j] < arrs[min_index]){
                min_index = j;
            }
        }
        swap(arrs[min_index], arrs[i]);
    }
}

int main(){
    int arrs[] = {2,5,7,3,4,1,6};
    int length = 7;

    cout<<"Array before sorting: ";
    for(int i=0; i<length; i++){
        cout<<arrs[i]<<" ";
    }
    cout<<"\nArray  after sorting: ";
    selectionSort(arrs, length);
    for(int i=0; i<length; i++){
        cout<<arrs[i]<<" ";
    }
}