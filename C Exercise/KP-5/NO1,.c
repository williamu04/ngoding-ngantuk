#include <stdio.h>

int main(){
    int hasil = 0;
    int jumlah = 0;
    int i = 1;
    while (i < 100)
    {
        printf("%d\n", i);
        i+=2;
        jumlah += i;
        hasil++;
    }
    printf("\nBanyaknya bilangan ganjil: %d\n", hasil);
    printf("Jumlah seluruh bilangan ganjil: %d", jumlah);
    return 0;
}