#include <stdio.h>

int main(){
    char nama[1000];
    printf("Masukkan nama mahasiswa     : ");
    scanf("%s", nama);

    int bahasa, mtk, ipa;
    printf("Masukkan nilai Bhs Indonesia: ");
    scanf("%d", &bahasa);
    
    printf("Masukkan nilai Matematika   : ");
    scanf("%d", &mtk);
    
    printf("Masukkan nilai IPA          : ");
    scanf("%d", &ipa);

    printf("--------------------------------------------\n");
    if (bahasa >= 60 && mtk >=70 && ipa >= 60)
    {
        printf("Status Kelulusan            : LULUS\n");
    } else {
        printf("Status Kelulusan            : TIDAK LULUS\n");
        printf("Sebab                       :\n");
        if (bahasa <= 60) printf("-   Nilai Bhs Indonesia kurang dari 60\n");
        if (mtk <= 70) printf("-   Nilai Matematika kurang dari 70\n");
        if (ipa <= 60) printf("-   Nilai IPA kurang dari 60\n");
    }
    return 0;
}