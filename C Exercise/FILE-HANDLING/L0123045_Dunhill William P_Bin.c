#include <stdio.h>

int main() {
    FILE *file;
    int num = 12345;

    // Membuat file binary dan menulis angka ke dalam file
    file = fopen("contoh.bin", "wb");
    if (file == NULL) {
        printf("Tidak dapat membuat file.\n");
        return 1;
    }
    fwrite(&num, sizeof(int), 1, file);
    fclose(file);

    // Membaca dan memodifikasi isi file
    int buffer;
    file = fopen("contoh.bin", "rb+");
    if (file == NULL) {
        printf("Tidak dapat membuka file.\n");
        return 1;
    }
    fread(&buffer, sizeof(int), 1, file);
    printf("Sebelum modifikasi: %d\n", buffer);

    // Modifikasi nilai dalam file
    buffer = 67890;
    fseek(file, 0, SEEK_SET);  // Kembali ke awal file
    fwrite(&buffer, sizeof(int), 1, file);
    fclose(file);

    // Membaca isi file setelah modifikasi
    file = fopen("contoh.bin", "rb");
    if (file == NULL) {
        printf("Tidak dapat membuka file.\n");
        return 1;
    }
    fread(&buffer, sizeof(int), 1, file);
    printf("Setelah modifikasi: %d\n", buffer);
    fclose(file);

    return 0;
}
