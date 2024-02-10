#include <stdio.h>
#include <stdlib.h>

void tulis_file(char nama_file[], char isi[]) {
    FILE *file = fopen(nama_file, "w");
    if (file != NULL) {
        fputs(isi, file);
        fclose(file);
        printf("File %s sudah ditulis\n", nama_file);
    } else {
        printf("File %s tidak dapat ditulis\n", nama_file);
    }
}

void duplikasi_file(char nama_file_asli[], char nama_file_duplikat[]) {
    FILE *file_asli = fopen(nama_file_asli, "r");
    FILE *file_duplikat = fopen(nama_file_duplikat, "w");

    if (file_asli != NULL && file_duplikat != NULL) 
    {
        char jenis;
        while ((jenis = fgetc(file_asli)) != EOF) 
        {
            fputc(jenis, file_duplikat);
        }
        fclose(file_asli);
        fclose(file_duplikat);

        printf("File %s telah diduplikat ke %s\n", nama_file_asli, nama_file_duplikat);
    } else {
        printf("Tidak bisa duplikat\n");
    }
}

void baca_file(char nama_file[]) {
    FILE *file = fopen(nama_file, "r");

    if (file != NULL) {
        char jenis;

        printf("Isi file adalah %s:\n", nama_file);
        while ((jenis = fgetc(file)) != EOF) {
            putchar(jenis);
        }

        fclose(file);
    } else {
        printf("Gagal membaca file %s\n", nama_file);
    }
}

int main() {
    char nama_file_asli[100], nama_file_duplikat[100], isi_file_asli[1000];

    printf("Masukkan nama file asli: ");
    scanf("%s", nama_file_asli);

    printf("Masukkan nama file duplikat: ");
    scanf("%s", nama_file_duplikat);

    printf("Masukkan isi file asli:\n");
    scanf(" %[^\n]s", isi_file_asli);

    tulis_file(nama_file_asli, isi_file_asli);
    duplikasi_file(nama_file_asli, nama_file_duplikat);
    baca_file(nama_file_duplikat);

    return 0;
}