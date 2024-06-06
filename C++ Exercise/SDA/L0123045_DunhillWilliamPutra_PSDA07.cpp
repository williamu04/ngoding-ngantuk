#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum nama {
    Andi,
    Budi,
    Caca,
    Dedi,
    Endi,
    Fifi,
    Gaoa,
    Jumlah
};

enum teman {
    berteman,
    belum
};

teman pertemanan[Jumlah][Jumlah];


// Daftar Fitur
// Menambahkan mahasiswa baru beserta daftar teman-temannya.
// Menambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar.
// Menghapus mahasiswa beserta seluruh hubungan pertemanannya.
// Mencari teman bersama antara dua mahasiswa yang sudah terdaftar.
// Menampilkan daftar teman dari seorang mahasiswa tertentu.

void menu();
void tambah_mhs();
void tambah_hubung();
void hapus_mhs();
void cari_teman();
void show_teman();

void setHubungan(nama a, nama b);

int main(){
    // menentukan aksi
    pertemanan[Andi][Budi] = berteman;
    pertemanan[Budi][Andi] = berteman;
    pertemanan[Budi][Caca] = belum;
    
    int input;

    while (1)
    {
        menu();
        cout << "\nMasukkan input: ";
        cin >> input;   
        
        switch (input)
        {
        case 1:
            tambah_mhs();
            break;
        case 2: 
            tambah_hubung();
            break;
        case 3: 
            cari_teman();
            break;
        case 4:
            show_teman();
            break;
        case 5:
            hapus_mhs();
            break;
        case 6: 
            return 0;
            break;
        default:
            cout << "Input tidak valid" << endl;
            break;
        }
    }
}

void menu(){
    cout << "Menu" << endl;
    cout << "1. Tambahkan Nama Mahasiswa Baru" << endl;
    cout << "2. Hubungkan 2 Mahasiswa" << endl;
    cout << "3. Cari teman bersama dari 2 Mahasiswa" << endl;
    cout << "4. Tampilkan daftar teman dari seorang Mahasiswa" << endl;
    cout << "5. Hapus Mahasiswa dan hubungan teman" << endl;
    cout << "6. Keluar";
}

void tambah_mhs(){
    cout << "Menambahkan Mahasiswa" << endl;
}
void tambah_hubung(){
    cout << "Masukkan nama teman yang ingin dihubungkan: ";
    string input;
    cin >> input;

    // Convert the input string to lowercase for case-insensitive comparison
    // transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Check if the input string matches one of the elements in the enum nama
    for (int i = 0; i < Jumlah; i++) {
        string namaStr = to_string(static_cast<enum nama>(i));
        // transform(namaStr.begin(), namaStr.end(), namaStr.begin(), ::tolower);

        if (input == namaStr) {
            nama nama1 = static_cast<enum nama>(i);
            cout << "Masukkan nama teman yang ingin dihubungkan: ";
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::tolower);

            for (int j = 0; j < Jumlah; j++) {
                string namaStr2 = to_string(static_cast<enum nama>(j));
                transform(namaStr2.begin(), namaStr2.end(), namaStr2.begin(), ::tolower);

                if (input == namaStr2) {
                    nama nama2 = static_cast<enum nama>(j);
                    setHubungan(nama1, nama2);
                    cout << "Menghubungkan 2 Mahasiswa" << endl;
                    return;
                }
            }
        }
    }

    cout << "Nama tidak ditemukan" << endl;
}
void hapus_mhs(){
    cout << "Menghapus Mahasiswa" << endl;
}
void cari_teman(){
    cout << "Mencari Teman" << endl;
}
void show_teman(){
    cout << "Menampilkan Teman" << endl;
}

void setHubungan(nama a, nama b){
    pertemanan[a][b] = berteman;
    pertemanan[b][a] = berteman;
}