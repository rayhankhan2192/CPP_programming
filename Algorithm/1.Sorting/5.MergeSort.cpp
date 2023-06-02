#include<iostream>
using namespace std;

void mergeSort(int arr[], int length);
void partitions(int arr[], int low, int high);
void mergeArray(int arr[], int low, int mid, int high);

void mergeSort(int arr[], int length){
    partitions(arr, 0, length-1);
}
void mergeArray(int arr[], int low, int mid, int high){
    int left_length  = mid-low+1;//store left length of the array [low to mid]
    int right_length = high-mid;//store right lenght of the array [mid to high]
    int temp_left[left_length];//two temporary array to store right and left value of the portions
    int temp_right[right_length];
    for(int i=0; i<left_length; i++){//copy all element of the array[low to mid]
        temp_left[i] = arr[low+i];
    }
    for(int i=0; i<right_length; i++){//copy all element of the array [mid+1 to high]
        temp_right[i] = arr[mid+1+i];
    }
    int i,j,k;
    for(i=0, j=0, k=low; k<=high; k++){
        if((i<left_length) && (j >= right_length || temp_right[j] >= temp_left[i]))
        {
            arr[k] = temp_left[i];
            i++;
        }else{
            arr[k] = temp_right[j];
            j++;
        }
    }
}
void partitions(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        partitions(arr, low, mid);
        partitions(arr, mid+1, high);
        mergeArray(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {83,5,1,3,4,2,221};
    int length = 7;
    cout<<"Array before sorting: ";
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nArray after  sorting: ";
    mergeSort(arr,length);
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }
}

