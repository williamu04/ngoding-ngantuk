#include <stdio.h>
#include <string.h>

typedef enum
{
    januari=1, februari, maret, april, mei, juni, juli, agustus, september, oktober, november, desember
} bulan;

typedef struct
{
    int tgl;
    bulan bln;
    int thn;
} date;

int kabisat(int tahun) {
    return (((tahun % 4 == 0) && (tahun % 100 != 0)) || (tahun % 400 == 0));
}

bulan keString(char *str){
    if (strcmp(str, "januari")==0) return januari;
    else if (strcmp(str, "februari")==0) return februari;
    else if (strcmp(str, "maret")==0) return maret;
    else if (strcmp(str, "april")==0) return april;
    else if (strcmp(str, "mei")==0) return mei;
    else if (strcmp(str, "juni")==0) return juni;
    else if (strcmp(str, "juli")==0) return juli;
    else if (strcmp(str, "oktober")==0) return oktober;
    else if (strcmp(str, "november")==0) return november;
    else if (strcmp(str, "desember")==0) return desember; 
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
    char bulan[15];
    printf("Waktu awal\n");
    printf("Masukkan tanggal: ");
    scanf("%d", &awal.tgl);
    printf("Masukkan bulan: ");
    scanf("%s", bulan);
    printf("Masukkan tahun: ");
    scanf("%d", &awal.thn);
    awal.bln = keString(bulan);

    printf("Waktu akhir\n");
    printf("Masukkan tanggal: ");
    scanf("%d", &akhir.tgl);
    printf("Masukkan bulan: ");
    scanf("%s", bulan);
    printf("Masukkan tahun: ");
    scanf("%d", &akhir.thn);
    akhir.bln = keString(bulan);

    selisih(awal, akhir);
    return 0;
}