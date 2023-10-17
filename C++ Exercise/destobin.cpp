#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int c;
    char buffer[64];
    cout << "masukkan desimal";
    cin >> c;
    cout << "berikut bentuk binarinya: " << itoa(c, buffer, 2) << endl;
    cout << "berikut bentuk hexadesimalnya: " << itoa(c, buffer, 16) << endl;
    cout << "berikut bentuk oktadesimalnya: " << itoa(c, buffer, 8) << endl;


}