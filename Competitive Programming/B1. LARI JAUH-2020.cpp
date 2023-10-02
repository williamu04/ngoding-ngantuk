#include <iostream>

using namespace std;

int main() {
    long int jumlahPatok, banyak_bebek; 
    cin >> jumlahPatok >> banyak_bebek;
    long int A[jumlahPatok+1], jarak_tempuh_bebek[banyak_bebek+1];
    int jarak[jumlahPatok+1], jangkauan[banyak_bebek+1];
    int i, j;
    jarak[0] = 0;
    for ( i=1; i<=jumlahPatok; i++ ){
        cin >> A[i];
        jarak[i] = jarak[i-1] + A[i];
    }
    for ( i=1; i<=banyak_bebek; i++ ){
        cin >> jarak_tempuh_bebek[i];
    }
    for (i=0; i<=banyak_bebek; i++){
        j = 0;
        while (j <= jumlahPatok){
            if (jarak_tempuh_bebek[i] >= jarak[j]){
                jangkauan[i] = j;
            }
            j++;
        }
    }
    for (i=1; i<=banyak_bebek; i++){
        cout << jangkauan[i] << endl;
    }
    return 0;
}
