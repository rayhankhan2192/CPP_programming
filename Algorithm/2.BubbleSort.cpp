#include<iostream>
using namespace std;

void bubblesort(int arras[], int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-1; j++){
            if(arras[j] > arras[j+1]){
                swap(arras[j], arras[j+1]);
            }
        }
    }
}

int main()
{
    int arras[] = {10,1,9,3,6,2,8,7,4,5};
    int length = 10;
    cout<<"Array before sorting: ";
    for(int i=0; i<length; i++){
        cout<<arras[i]<<" ";
    }

    cout<<"\nArray after  sorting: ";
    bubblesort(arras, length);
    for(int i=0; i<length; i++){
        cout<<arras[i]<<" ";
    }
}