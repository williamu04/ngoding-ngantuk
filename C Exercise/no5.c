#include <stdio.h>

int main(){
    /*
    Diagram batang memperesentasikan jumlah mahasiswa laki dan perempuan
    */

    int cwo, cwe;

    printf("Jumlah mahasiswa laki-laki: ");
    scanf("%d", &cwo);

    printf("Jumlah mahasiswa perempuan: ");
    scanf("%d", &cwe);


    printf("\nLaki-laki: ");
    for (int i = 0; i < cwo; i++)
    {
        printf("*");
    }
    printf("\nPerempuan: ");
    for (int i = 0; i < cwe; i++)
    {
        printf("*");
    }
    return 0;
}