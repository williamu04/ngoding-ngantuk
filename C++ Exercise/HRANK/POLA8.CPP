//Bagas Rizki Gunardi
//L0123034
//Pola 8

#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= n / 2) {
                if (j < i || j > n - i + 1) {
                    cout << "  ";
                } else {
                    cout << "* ";
                }
            } else {
                if (j <= n - i || j >= i + 1) {
                    cout << "  ";
                } else {
                    cout << "* ";
                }
            }
        }
        cout << endl;
    }

return 0;}
