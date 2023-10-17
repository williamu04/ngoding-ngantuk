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
