// #include <iostream>
// using namespace std;

// int main() {

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || abs(i - n/2) + abs(j - n/2) >= n/2) {
//                 cout << "* ";
//             } else {
//                 cout << "  ";
//             }
//         }
//         cout << "\n";
//     }
// return 0;}

#include <iostream> 
using namespace std;

// int main() {
// int n;
// cin >> n;

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n - abs(i - n / 2); j++) {
//         if (j == i || j == n - abs(i - n / 2) - 1) {
//             cout << "  ";
//         } else {
//             cout << "* ";
//         }
//     }
//     cout << "\n";
// }
// return 0;
// }

#include <iostream> 
using namespace std;

int main() {

int n;
cin >> n;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Ubah kondisi j != n/2 menjadi i == j atau i + j == n - 1
        if (false || i == j || i + j == n - 1 || j == n/2 || i == n/2) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}
return 0;}