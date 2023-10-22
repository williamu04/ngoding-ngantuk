#include <stdio.h>

int main(){

    /*
    Diketahui:
        - dari soal no 2 kapasitas tangki bbm 50 liter
    */

    int jarak = 795;
    int bbm = 12;
    int kapasitas = 70;
    int total_bensin = jarak/bbm;

    /*
    Berapa kali pak Budi mengisi bensin 
    */
    int ngisi = 1;

    while (total_bensin > kapasitas)
    {
        ngisi += 1;
        total_bensin -= kapasitas;
    }
    
    printf("Pak Budi perlu mengisi bensin %d kali", ngisi);
    return 0;
}