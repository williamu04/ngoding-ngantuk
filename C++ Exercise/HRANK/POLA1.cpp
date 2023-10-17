//naufal Hisyam Muzakki pola 
#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    if (input% 2 == 0) {
        input = input - 1;
    }
    int baris = input/2 + 1;
    int spasi = 0;
    int test = input;
    for (int i = baris; i > 1 ; i--) {
        if (spasi != 0) {
            for (int a = 0; a < spasi; a++) {
                cout << " ";
            }
        }
        for (int j = 1 ; j<= test; j++){
                if (j % 2 == 0){
                    cout << "   ";
                }else{
                    cout << "*";
                }

        }

        cout << endl;
        test = test - 2;
        spasi = spasi + 2;
    }
    int baris2 = input/2;
    for (int i = 0; i <= baris2 ; i++) {
        if (spasi != 0) {
            for (int a = 0; a < spasi; a++) {
                cout << " ";
            }
        }

        for (int j = 1 ; j<= test; j++){
            if (j % 2 == 0){
                cout << "   ";
            }else{
                cout << "*";
            }

        }

        cout << endl;
        test = test + 2;
        spasi = spasi - 2;
    }
    return 0;
}