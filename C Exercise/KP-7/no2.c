#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int random = rand() % 100 + 1;
    int tebak;
    int bawah = 0, atas = 100;
    printf("Permainan tebak bilangan\n------------------------\n");

    while (1)
    {
        printf("Tebakan Anda: ");
        scanf("%d", &tebak);

        if (tebak == random)
        {
            printf("Tebakan anda BENAR :D\n");
            printf("Tebakan bawah terdekat: %d\n", bawah);
            printf("Tebakan atas terdekat: %d\n", atas);
            break;
        } else if (tebak > random)
        {
            printf("Tebakan anda terlalu BESAR :(\n");
            if (tebak < atas)
            {
                atas = tebak;
            }
        } else if (tebak < random)
        {
            printf("Tebakan anda terlalu KECIL :(\n");
            if (tebak > bawah)
            {
                bawah = tebak;
            }
        }
    }
    return 0;
}
