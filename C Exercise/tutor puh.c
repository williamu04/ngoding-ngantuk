#include <stdio.h>

int main()
{
    char input; // variabel char untuk menyimpan input user
    printf("Masukkan satu huruf antara A-D: "); // menampilkan pesan untuk user
    scanf("%c", &input); // membaca input user dan menyimpannya di variabel input

    switch(input) // menggunakan switch untuk memeriksa input user
    {
        case 'A': // jika input user adalah A
            printf("Anda memilih A\n"); // menampilkan output yang sesuai
            break; // keluar dari switch
        case 'B': // jika input user adalah B
            printf("Anda memilih B\n"); // menampilkan output yang sesuai
            break; // keluar dari switch
        case 'C': // jika input user adalah C
            printf("Anda memilih C\n"); // menampilkan output yang sesuai
            break; // keluar dari switch
        case 'D': // jika input user adalah D
            printf("Anda memilih D\n"); // menampilkan output yang sesuai
            break; // keluar dari switch
        default: // jika input user bukan A, B, C, atau D
            printf("Input tidak valid\n"); // menampilkan output yang sesuai
            break; // keluar dari switch
    }

    return 0;
}
