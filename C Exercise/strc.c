#include <stdio.h>

typedef struct matkul
{
    int id;
    char nama[100];
    int nilai;
} matkul;

int main(){
    int n;
    printf("Banyak matkul: ");
    scanf("%d", &n);

    matkul smst1[100];

    for (int i = 0; i < n; i++)
    {
        printf("Nama matkul: ");
        scanf("%s", smst1[i].nama);
        printf("Nilai: ");
        scanf("%d", &smst1[i].nilai);
    }

    printf("Id\tMatkul\t\tNilai\n");
    for (int i = 0; i < n; i++)
    {
        smst1[i].id = i+1;
        printf("%d\t%s\t\t%d\n", smst1[i].id, smst1[i].nama, smst1[i].nilai);
    }
    return 0;
}
