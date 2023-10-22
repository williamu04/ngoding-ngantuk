#include <stdio.h>

int main(){
    printf("===========================================\nSTRUK RINCIAN GAJI KARYAWAN\n");
    printf("------------------------------------------------------\n");

    char nama[50];
    char gol;

    printf("Nama Karyawan           : ");
    scanf("%s", nama);
    printf("Golongan                : ");
    scanf(" %c", &gol);

    printf("------------------------------------------------------\n");
    
    int pokok; 
    float pot;

    switch (gol)
    {
    case 'A':
        pokok = 10000000;
        pot = 0.025;
        break;
    case 'B' :
        pokok = 8500000;
        pot = 0.02;
        break;
    case 'C' :
        pokok = 7000000;
        pot = 0.015;
        break;
    case 'D' :
        pokok = 5500000;
        pot = 0.01;
        break;
    }
    
    float tunj_IS = 0.1;
    float tunj_A = 0.05;

    printf("Gaji Pokok              : Rp %d\n", pokok);
    printf("Tunjangan Istri/Suami   : Rp %.0f\n", pokok*tunj_IS);
    printf("Tunjangan Anak          : Rp %.0f\n", pokok*tunj_A);

    printf("------------------------------------------------------ +\n");

    int gaji_kotor = pokok + pokok*(tunj_A+tunj_IS);
    int potongan = gaji_kotor*pot;

    printf("Gaji Kotor              : Rp %d\n", gaji_kotor);
    printf("Potongan    (%.1f%)      : Rp %d\n", pot*100, potongan);

    printf("------------------------------------------------------ -\n");
    printf("Gaji Bersih             : Rp %d\n", gaji_kotor-potongan);    
}
