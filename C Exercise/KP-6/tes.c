#include <stdio.h>
#include <string.h>

int main(){
    float a[2][2], b[2][2], result[2][2];

    printf("Masukkan elemen matriks pertama\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Masukkan a%d%d: ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
        
    }
    
    printf("Masukkan elemen matriks kedua\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Masukkan b%d%d: ", i+1, j+1);
            scanf("%f", &b[i][j]);
        }
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Hasil: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.f  ", result[i][j]);
        }
        printf("\n");
    }
}















// int main(){
//     int test[2][3][2];
//     printf("Masukkan 12 bilangan:\n");
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             for (int k = 0; k < 2; k++)
//             {
//                 scanf("%d", &test[i][j][k]);
//             }
//         }
//     }

//     printf("\nMenampilkan nilai: \n");
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             for (int k = 0; k < 2; k++)
//             {
//                 printf("test[%d][%d][%d] = %d\n", i, j, k, test[i][j][k]);
//             }
//         }
//     }
//     return 0;
// }






// int main(){
//     char a[20] = "Program";
//     char b[20] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};
//     printf("Hasil strlen = %zu \n", strlen(a));

//     strcpy(a, b);
//     printf("hasil strcpy: ");
//     puts(b);

//     int h = strcmp(a, b);
//     printf("hasil strcmp: %d\n", h);

//     strcat(a, b);
//     printf("hasil strcat: \n");
//     puts(a);
//     puts(b);

//     return 0;
// }












// void tampil(char str[]);

// int main(){
//     char str[50];
//     printf("Masukkan string: ");
//     fgets(str, sizeof(str), stdin);
//     tampil(str);
//     return 0;
// }

// void tampil(char str[]){
//     printf("String Output: ");
//     puts(str);
// }