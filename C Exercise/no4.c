#include <stdio.h>

int main(){
    /*
    Diketahui:
        - jarak kota A - B adalah 125 km
        - rata-rata kecepatan 62 km/jam
    */

    float jarak_AB = 125;
    float kecepatan_AB = 62;

    /*
    Pak Amir Melanjutkan perjalanan ke C berjarak 256 km
    kecepatan 70 km/jam 
    */

    float jarak_BC = 256;
    float kecepatan_BC = 70;

    /*
    Berangkat dari A pukul 6.00, istirahat di B 45 menit = 0.75 jam
    pukul berapa sampai di C!
    */

    float waktu_AB = jarak_AB/kecepatan_AB;
    float waktu_BC = 0.75 + jarak_BC/kecepatan_BC;

    float total_waktu = waktu_AB + waktu_BC;

    printf("Total waktu tempuh Pak Amir adalah: %.2f jam", total_waktu);
    return 0;
}