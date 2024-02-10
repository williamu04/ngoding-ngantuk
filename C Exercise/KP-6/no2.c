#include <stdio.h>

int main(){
    int n;
    printf("Masukkan elemen bilangan (1-100): ");
    scanf("%d", &n);
    float k[n];
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan bilangan%d : ", i);
        scanf("%f", &k[i]);
    }
    float t = 0;
    for (int i = 0; i < n; i++)
    {
        t += k[i];
    }
    printf("Rata-rata bilangan adalah: %.2f", t/n);
}