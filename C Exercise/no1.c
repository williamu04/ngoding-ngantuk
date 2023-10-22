#include <stdio.h>

int main(){

    /*
    Diketahui:
        - tarif sewa Rp 200.000 untuk 12 jam pertama
        - berikutnya Rp 10.000 / jam
    */
    int tarif = 200000;
    int tarif_lanjut = 10000;

    /*
    seorang customer parkir dari jam 6.00 sampai jam 23.50 (pada hari yang sama)
    tentukan total biaya parkir!
    */

    int waktu = 18; //23.50 - 06.00 = 17.50 dibulatkan 18 jam
    int total_biaya = tarif + tarif_lanjut * (waktu-12);

    printf("Total biaya parkir adalah: %d", total_biaya);
    return 0;
}