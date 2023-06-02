#include <stdio.h>
int main(){
    int array[] = {2, 4, 8, 11, 12, 14, 17, 19};
    int length= 7;
    int left = 0, right = length, middle,value;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    while (left <= right){
        middle = (right + left) / 2;
        if (array[middle] == value){
            printf("\n%d is found in position %d\n\n",value, middle + 1);
            return 0;
        }
        else if (array[middle] < value){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    printf("\nValue not found!\n");
    return 0;
}
