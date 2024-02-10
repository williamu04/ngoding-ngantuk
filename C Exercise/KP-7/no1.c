#include <stdio.h>
#include <string.h>

int main(){
    char kata[10][100];
    printf("Masukkan kata: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", kata[i]);
    }

    for (int i = 0; i < 9; i++) // Mulai dari indeks 0 dan berhenti sebelum indeks terakhir
    {
        for (int j = 0; j < 9 - i; j++) // Lakukan operasi pengurutan bubble untuk setiap pasangan kata
        {
            if (strcmp(kata[j], kata[j+1]) > 0) // Gunakan fungsi strcmp untuk membandingkan string
            {
                char temp[100]; // Pastikan array temp cukup besar untuk menampung string
                strcpy(temp, kata[j]);
                strcpy(kata[j], kata[j+1]);
                strcpy(kata[j+1], temp);
            }
        }
    }
    
    printf("\nHasil urutan: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", kata[i]);
    }
}
