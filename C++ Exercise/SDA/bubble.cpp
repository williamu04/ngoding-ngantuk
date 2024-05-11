#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int& swapCount);

int main() {
    int B[] = {8, 2, 1, 3, 10, 5};
    int n = sizeof(B) / sizeof(B[0]);
    int swapCount = 0;

    cout << "Array awal: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    bubbleSort(B, n, swapCount);

    cout << "Array terurut: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    cout << "Jumlah swap: " << swapCount << endl;

    return 0;
}

void bubbleSort(int arr[], int n, int& swapCount) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }
}