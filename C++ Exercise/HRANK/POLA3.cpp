//Bagas Rizki Gunardi
//L0123034
//Pola 3

#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 1; i -= 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

return 0;}
