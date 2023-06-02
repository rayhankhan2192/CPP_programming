#include <bits/stdc++.h>
using namespace std;

int partitons(int arr[], int low, int high);
void quick_sort(int arr[], int length);
void quickSort_reursion(int arr[], int low, int high);

void quick_sort(int arr[], int length){
    quickSort_reursion(arr, 0, length-1);
}

void quickSort_reursion(int arr[], int low, int high){
    if(low<high){
        int pivot_index = partitons(arr, low, high);
        quickSort_reursion(arr, low, pivot_index-1);
        quickSort_reursion(arr, pivot_index+1, high);
    }
}

int partitons(int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int ends = high;

    while (start < ends){
        while (arr[start] <= pivot){
            start++;
        }
        while (arr[ends] > pivot){
            ends--;
        }
        if (start < ends){
            swap(arr[start], arr[ends]);
        }
    }
    swap(arr[low],arr[ends]);
    return ends;
}

int main(){
    int arr[] = {200, 400, 100, 500, 300};
    int length = 5;
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
        printf("\n");
    quick_sort(arr,length);
    for(int i=0; i<length; i++)
        cout<<arr[i]<<" ";
}
