#include <stdio.h>

int main(){
    int n;
    printf("Masukkan elemen bilangan (1-100): ");
    scanf("%d", &n);
    float k[n];
    float besar=0, kecil=k[0];
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan bilangan%d : ", i);
        scanf("%f", &k[i]);
        if (k[i] > besar)
        {
            besar = k[i];
        }
        if (k[i] < kecil)
        {
            kecil = k[i];
        }
        
    }
    printf("Elemen terbesar = %.2f\n", besar);
    printf("Elemen terkecil = %.2f", kecil);
}