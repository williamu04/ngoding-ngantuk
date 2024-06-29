#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate an array with random elements
vector<int> generateRandomArray(long size) {
    vector<int> arr;
    for (long i = 0; i < size; ++i) {
        arr.push_back(rand() % 99999 + 1);
    }
    return arr;
}

// Function for Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function for Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function for Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Function for Merge Sort
void merge(vector<int>& left, vector<int>& right, vector<int>& arr) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}
void mergeSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortHelper(arr, low, pivot - 1);
        quickSortHelper(arr, pivot + 1, high);
    }
}
void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

int main() {
    srand(time(nullptr));

    char choice;
    do {
        int total;
        cout << "==============================================" << endl;
        cout << "Masukkan jumlah elemen acak array: ";
        cin >> total;
        // Generate an array with total random elements
        vector<int> array = generateRandomArray(total);

        // Ask the user to choose a sorting algorithm
        cout << "Pilihan sorting algorithm:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;

        int algoChoice;
        cout << "Pilih: ";
        cin >> algoChoice;

        clock_t start_time = clock();

        switch (algoChoice) {
            case 1:
               bubbleSort(array);
                cout << "Algoritma yang digunakan: Bubble Sort" << endl;
                break;
            case 2:
                insertionSort(array);
                cout << "Algoritma yang digunakan: Insertion Sort" << endl;
                break;
            case 3:
                selectionSort(array);
                cout << "Algoritma yang digunakan: Selection Sort" << endl;
                break;
            case 4:
                mergeSort(array);
                cout << "Algoritma yang digunakan: Merge Sort" << endl;
                break;
            case 5:
                quickSort(array);
                cout << "Algoritma yang digunakan: Quick Sort" << endl;
                break;
            default:
                cout << "Pilihan algoritma tidak valid." << endl;
                return 1;
        }

        clock_t end_time = clock();
        double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Jumlah elemen array: " << total << endl;
        cout << "Waktu yang diperlukan: " << elapsed_time << " detik" << endl;

        cout << "Apakah Anda ingin melanjutkan? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}