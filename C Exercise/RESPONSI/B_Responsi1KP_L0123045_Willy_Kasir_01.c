#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct dengan nama barang memiliki elemen berupa nama dan harga
typedef struct {
    char* nama;
    int harga;
} Barang;

//fungsi void yang menyetak halaman utama 
void menu(){
    printf("--------------------------\n");
    printf("====  JOYA JAYA MART  ====\n");
    printf("--------------------------\n");
    printf("1. Cetak Daftar Barang\n2. Cek Harga Barang\n3. Total Belanja\n4. Exit\nPilih (1/2/3/4) ? ");
}

// fungsi rekursif yang menyetak daftar barang sesuai dengan perintah dari menu utama
void cetakDaftar(Barang *daftar, int arr_length){
    if (arr_length >= 0) {
        printf("Nama Barang: %s\n   Harga Barang: Rp %d\n", daftar[arr_length].nama, daftar[arr_length].harga);
        cetakDaftar(daftar, arr_length-1);
    }
}

// fungsi untuk menjumlahkan total harga barang sesuai dengan input barang
void total(Barang *daftar, int arr_length){
    int n = 0;
    printf("Masukkan nama barang satu per satu & ketik selesai jika sudah : \n");

    while (1)
    {
        char barang[10];
        printf("Nama barang : ");
        scanf("%s", barang);

        if (strcmp(barang, "selesai") == 0) { //jika nama barang diinputkan selesai maka program akan berhenti dan menyetak total harga
            break;
        }   

        for (int i = 0; i < arr_length; i++) {
            if (strcmp(daftar[i].nama, barang) == 0) {
                n += daftar[i].harga;
                break;
            }
        }
    }
    printf("Total belanja anda adalah : Rp %d\n\n", n);
}

// fungsi untuk menyetak harga barang yang ingin dicek dengan menginputkan nama barang 
void cari(Barang *daftar, int arr_length){
    printf("Masukkan nama barang yang ingin dicek harganya : ");
    char barang[10];
    scanf("%s", barang);
    int fond = 1; //inisiasi fond adalah 1
    for (int i = 0; i < arr_length; i++) {
        if (strcmp(daftar[i].nama, barang) == 0) {
            printf("Harga %s adalah Rp %d\n\n", barang, daftar[i].harga);    
            fond = 0; // jika barang tersedia di katalog maka mengubah fond menjadi 0 (false)
            break;
        }
    }
    if (fond) { //jika fond masih bernilai benar, maka akan menyetak di bawah ini
        printf("Maaf barang tersebut tidak tersedia di katalog\n");
    }
}

int main() {
    // struct barang yang menyimpan nama dan harga barang sesuai urutan
    Barang daftar[5]; 
    daftar[0].nama = "sapi";
        daftar[0].harga = 15000;
    daftar[1].nama = "kambing";
        daftar[1].harga = 10000;
    daftar[2].nama = "ayam";
        daftar[2].harga = 4000;
    daftar[3].nama = "lele";
        daftar[3].harga = 2000;
    daftar[4].nama = "gurame";
        daftar[4].harga = 6000;
    daftar[5].nama = "nila";
        daftar[5].harga = 5500;
    
    int i;
    do {
        menu(); //menampilkan fungsi menu utama
        scanf("%d", &i);
        // switch case untuk menentukan aksi setelah input yang diberikan sesuai dengan yang ada di menu utama
        switch (i)
        {
        case 1:
            char apa[3];
            printf("Cetak Daftar Barang dari Katalog? (Ya/Tidak) ");
            scanf("%s", apa);
            printf("\n");
            if (strcmp(apa, "Ya") == 0) {
            cetakDaftar(daftar, sizeof(daftar)/sizeof(daftar[0]));
            }
            break;
        case 2:
            cari(daftar, sizeof(daftar)/sizeof(daftar[0])+1);
            break;
        case 3:
            total(daftar, sizeof(daftar)/sizeof(daftar[0])+1);
            break;
        default:
            break;
        }
    } while (i != 4); // jika input adalah 4 (exit) maka program berhenti
    return 0;
}
