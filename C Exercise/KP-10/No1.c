#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nama[100];
    int nim, nilai;
} DataMahasiswa;

int main() {
    DataMahasiswa mahasiswa;
    char lanjut;
    FILE *file;

    file = fopen("data_mahasiswa.bin", "ab");
    if (file == NULL) {
        perror("Tidak dapat membuka file");
        exit(1);
    }

    do {
        printf("Nama : ");
        scanf("%s", mahasiswa.nama);
        printf("NIM : ");
        scanf("%d", &mahasiswa.nim);
        printf("Nilai : ");
        scanf("%d", &mahasiswa.nilai);

        if (fwrite(&mahasiswa, sizeof(DataMahasiswa), 1, file) != 1)
        {
            printf("Gagal memasukkan data");
            exit(1);
        } else{
            printf("Data berhasil dimasukkan dalam file.\n");
        }
        printf("Apakah ingin memasukkan data lagi? (Y/N) ");
        scanf(" %c", &lanjut); 
    } while (lanjut == 'Y');

    fclose(file);

    return 0;
}
