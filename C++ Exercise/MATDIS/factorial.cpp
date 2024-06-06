#include <iostream>

using namespace std;

// int factorial(int n){
//     if (n == 0)
//     {
//         return 1;
//     } else if (n > 0)
//     {
//         return n*factorial(n-1);
//     } else {
//         throw runtime_error("Bilangan tidak valid");
//     }
// }


// int main(){
//     int n;
//     cout << "Input bilangan: ";
//     cin >> n;
//     cout << n << "! adalah: ";
//     cout << factorial(n);
// }

/*
1 + 2 + 3 + ... + n = (n/2)*(1+n)


combinatorik(n, k)
    -> combinatorik(n-1, k) + combinatorik(n-1, k-1)
    -> n! / k!(n-k)!

linier search rekursif

*/

int findIndex(int arr[], int size, int target, int currentIndex = 0) {
    if (currentIndex >= size) {
        return -1; // target not found
    }
    if (arr[currentIndex] == target) {
        return currentIndex;
    }
    return findIndex(arr, size, target, currentIndex + 1);
}

int pow(int a, int n){
    if (n == 0 && a > 0)
    {
        /* code */
        return 1;
    } else if (n > 0 && a > 0)
    {
        /* code */
        return pow(a, n-1)*a;
    } else {
        throw runtime_error("Bilangan should greater than 0");
    }
}

int main(){
    int a, n;
    cout << "Masukkan basis: ";
    cin >> a;
    cout << "Masukkan pangkat: ";
    cin >> n;
    cout << "Hasilnya adalah: " << pow(a, n);
}