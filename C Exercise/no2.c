#include <stdio.h>

int main(){

    /*
    Diketahui:
        - jarak kota A - C = 795 km
        - konsumsi bbm mobil pak Budi 1:12 
    */

    int jarak = 795;
    int bbm = 12;

    /*
    Bensin yang diperlukan untuk perjalanan tersebut
    */

    float total_bensin = jarak/bbm;

    printf("Total bensin yang diperlukan pak Budi adalah: %.1f liter", total_bensin);
    return 0;
}