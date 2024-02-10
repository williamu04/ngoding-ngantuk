#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_menu(){
    printf("Manajemen File\n");
    printf("1. Buat File\n2. Ubah nama file\n3. Hapus file\n4. Keluar");
}

void buat_file(FILE *file){
    char nama[64];
    char isi[255];
    
    printf("Buat nama file: ");
    scanf("%63s", nama); // Menambahkan limit pada scanf untuk mencegah buffer overflow
    file = fopen(nama, "w");
    
    if (file == NULL) {
        printf("File tidak dapat dibuat\n");
        return;
    }
    
    printf("Isi file: ");
    getchar(); // Membersihkan buffer input
    fgets(isi, sizeof(isi), stdin); // Membaca seluruh baris teks
    isi[strcspn(isi, "\n")] = 0; // Menghapus newline character
    
    if (fwrite(isi, strlen(isi), 1, file) != 1) {
        printf("File gagal dibuat\n");
    } else {
        printf("File berhasil dibuat\n"); 
    }
    
    fclose(file); // Menutup file
}


void ubah_file(){
    
    char name[64], buff[64];
    printf("Nama file yang akan diubah: ");
    scanf("%s", name);
    printf("Nama file yang baru: ");
    scanf("%s", buff);
    if (rename(name, buff) == 0) printf("Nama file berhasil diubah");
    else printf("Nama file gagal diubah");
}

void hapus_file(){
    char buff[64];
    printf("Nama file yang akan dihapus: ");
    scanf("%s", buff);

    if(remove(buff) == 0) printf("File berhasil dihapus");
    else printf("File gagal dihapus");
}


int main(){
    int n;
    FILE *file;

    do
    {
        main_menu();
        printf("\nMasukkan perintah: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            buat_file(&file);
            break;
        case 2:
            ubah_file();
            break;
        case 3:
            hapus_file();
            break;
        default:
            printf("Sampai Jumpa!");
            break;
        }
    } while (n != 4);
    
    return 0;
}

