#include <stdio.h>

int main(){
    int r,c;
    printf("Masukkan baris dan kolom\nBaris: ");
    scanf("%d", &r);
    printf("Kolom: ");
    scanf("%d", &c);

    int mat[r][c];

    printf("Masukkan elemen matriks\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Masukkan elemen a%d%d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    
    printf("\n\nMatriks awal:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
    
    printf("Transpose matriks:\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d  ", mat[j][i]);
        }
        printf("\n");
    }

}
