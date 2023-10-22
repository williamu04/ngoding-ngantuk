#include <stdio.h>
#include <stdlib.h>

int main(){

    srand(time(NULL));
    int random = rand() % 100 + 1;

    int tebak;
    
    printf("Selamat datang di permainan tebak Angka.\nSaat ini sistem sudah menentukan sebuah bilangan random.\nSilakan tebak bilangan berapa tersebut\n\n");

    while (1)
    {
        printf("Tebakan Kamu: ");
        scanf("%d", &tebak);

        if (tebak == random)
        {
            printf("Tebakanmu BENAR :D\n");
            break;
        } else if (tebak > random)
        {
            printf("Tebakanmu terlalu BESAR :(\n");
        } else if (tebak < random)
        {
            printf("Tebakanmu terlalu KECIL :(\n");
        }  
    }
    return 0;

}