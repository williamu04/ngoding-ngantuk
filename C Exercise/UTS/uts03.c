#include <stdio.h>

int pilih(int i, int sal){
    int d;
    if (i == 1){
        printf("Jumlah setor: ");
        scanf("%d", &d);
        printf("Jumlah saldo anda sekarang: Rp %d", sal+d);
    } else if (i == 2) {
        printf("Jumlah ambil: ");
        scanf("%d", &d);
        if (sal-d < 0) {
            printf("Saldo minimum anda adalah Rp 10000");
        } else {
            printf("Saldo anda sekarang: Rp %d", sal-d);
        }
    } else if (i == 3) {
        return 0;
    }
}

int main(){
    printf("----------------------------------------\n");
    printf("PT. BANK SYARIAH BENERAN\n");
    printf("----------------------------------------\n");

    int salawal = 10000;
    int pilihan;

    printf("Saldo : %d\n", salawal);
    printf("Menu Transaksi\n");
    printf("1. Setor Tabungan\n2. Ambil Tabungan\n3. Exit\n");
    printf("Pilihan menu (1/2/3)? ");
    scanf("%d", &pilihan); 
    
    pilih(pilihan, salawal);
}
