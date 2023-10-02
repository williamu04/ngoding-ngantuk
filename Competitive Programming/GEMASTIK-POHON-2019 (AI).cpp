#include <iostream> 
#include <cmath> 
#include <map> 
#define loop(i,n) for(int i=0; i<n; i++)
typedef map<double, double> mdd;
typedef double d;

using namespace std;

int main() { 
    int N, X, Y; 
    cin >> N >> X >> Y; 
    mdd angles; 
    int count = 0; 
    loop(i, N) { 
        int p, q; // Posisi pohon ke-i 
        cin >> p >> q; 
        d angle = atan2(q-Y, p-X); // Sudut antara Pak Blangkon dan pohon ke-i 
        d distance = sqrt((p-X)*(p-X) + (q-Y)*(q-Y)); // Jarak antara Pak Blangkon dan pohon ke-i 
        if (angles.count(angle) == 0) { 
            // Jika belum ada pohon dengan sudut yang sama 
            angles[angle] = distance; // Simpan sudut dan jaraknya 
            count++; // Tambahkan satu ke jumlah pohon yang terlihat 
        } else { 
            // Jika sudah ada pohon dengan sudut yang sama 
            if (distance < angles[angle]) { 
                // Jika jaraknya lebih kecil dari yang sudah ada 
                angles[angle] = distance; // Perbarui jaraknya 
                } 
            } 
        } 
    cout << count << endl; // Cetak jumlah pohon yang terlihat 
    return 0; 
}