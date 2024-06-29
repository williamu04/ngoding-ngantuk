#include <iostream>

using namespace std;

int findIndex(int arr[], int size, int target, int currentIndex = 0) {
    if (currentIndex >= size) {
        return -1; // target not found
    }
    if (arr[currentIndex] == target) {
        return currentIndex+1;
    }
    return findIndex(arr, size, target, currentIndex + 1);
}

int main(){
    int arr[] = {2, 3, 1, 5, 7, 6, 0, 4, 9};

    cout << findIndex(arr, 9, 5);
}