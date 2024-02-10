#include <stdio.h>

typedef struct date
{
    int tgl;
    int bln;
    int thn;
} date;

int kabisat(int tahun) {
    return (((tahun % 4 == 0) && (tahun % 100 != 0)) || (tahun % 400 == 0));
}

int getDays(int bulan, int tahun) {
    int daysInbulan[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (bulan == 2) {
        return daysInbulan[bulan] + kabisat(tahun);
    } else {
        return daysInbulan[bulan];
    }
}

void selisih(date dt1, date dt2) {
    int tahun, bulan, hari;

    // hitung hari
    hari = dt2.tgl - dt1.tgl;
    if (hari < 0) {
        dt2.bln--;
        hari += getDays(dt1.bln, dt1.thn);
    }

    bulan = dt2.bln - dt1.bln;
    if (bulan < 0) {
        dt2.thn--;
        bulan += 12;
    }

    tahun = dt2.thn - dt1.thn;

    printf("Selisih kedua waktu: %d hari, %d bulan, %d tahun\n", hari, bulan, tahun);
}

int main(){
    date awal, akhir;
    printf("Waktu awal\n");
    printf("Masukkan tanggal: ");
    scanf("%d", &awal.tgl);
    printf("Masukkan bulan: ");
    scanf("%d", &awal.bln);
    printf("Masukkan tahun: ");
    scanf("%d", &awal.thn);

    printf("Waktu akhir\n");
    printf("Masukkan tanggal: ");
    scanf("%d", &akhir.tgl);
    printf("Masukkan bulan: ");
    scanf("%d", &akhir.bln);
    printf("Masukkan tahun: ");
    scanf("%d", &akhir.thn);

    selisih(awal, akhir);
    return 0;
}