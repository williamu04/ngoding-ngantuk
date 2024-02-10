#include <stdio.h>
#include <stdlib.h>


// ini no 4
struct makul
{
    int nilai;
    char materi[30];
};

int main(){
    struct makul *ptr;
    int jml;
    printf("Masukkan jumlah data: ");
    scanf("%d", &jml);

    ptr = (struct makul *)malloc(jml*sizeof(struct makul));
    for (int i = 0; i <jml; i++)
    {
        printf("Masukkan nama materi dan nilainya: \n");
        scanf("%s %d", (ptr+i)->materi, &(ptr+i)->nilai);
    }

    printf("Informasi:\n");
    for (int i = 0; i < jml; i++)
    {
        printf("%s\t%d\n", (ptr+i)->materi, (ptr+i)->nilai);
    }

    free(ptr);
    ptr = NULL;
    return 0;
}






// ini no 3
// enum allfabet{
//     A = 1,
//     B = 2,
//     C = 4
// };

// int main(){
//     int kombinasi = A | C;
//     printf("%d", kombinasi);
//     return 0;
// }



// ini no 2
// union Job
// {
//     float gaji;
//     int jumlahKaryawan;
// } j;

// int main(){
//     j.gaji = 1500000;
//     j.jumlahKaryawan = 100;

//     printf("Gaji = %.1f\n", j.gaji);
//     printf("Jumlah Karyawan = %d", j.jumlahKaryawan);
//     return 0;
// }





// ini no 1
// struct student
// {
//     char nama[50];
//     int nim;
//     float nilai;
// } s;

// int main(){
//     printf("Masukkan informasi: \n");
//     printf("Masukkan nama: ");
//     fgets(s.nama, sizeof(s.nama), stdin);

//     printf("Masukkan NIM: ");
//     scanf("%d", &s.nim);
//     printf("Masukkan nilai: ");
//     scanf("%f", &s.nilai);

//     printf("Masukan informasi: \n");
//     printf("Nama: ");
//     printf("%s", s.nama);
//     printf("NIM: %d\n", s.nim);
//     printf("Nilai: %.f\n", s.nilai);

//     return 0;
// }

