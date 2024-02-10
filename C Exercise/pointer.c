#include <stdio.h>

void times(int *arr, int length){
    for (int i = 0; i < length; i++)
    {
        arr[i]*=2;
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    times(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}