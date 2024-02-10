#include <stdio.h>
#include <stdlib.h>

struct nomor
{
    int n1, n2, n3;
};

// // ini no 2
int main(){
    int n;
    struct nomor num;
    FILE *fptr;

    if ((fptr = fopen("program.bin", "rb")) == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fseek(fptr, -sizeof(struct nomor), SEEK_END);

    for (n = 1; n < 5; n++)
    {
        fread(&num, sizeof(struct nomor), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
        fseek(fptr, -2*sizeof(struct nomor), SEEK_CUR);
    }
    fclose(fptr);
    return 0;
       
}




// // ini no 1
// int main(){
//     int n;
//     struct nomor num;
//     FILE *fptr;

//     fptr = fopen("program.bin", "wb+");
//     for (int n = 1; n < 5; n++)
//     {
//         num.n1 = n;
//         num.n2 = 5*n;
//         num.n3 = 5*n + 1;
//         fwrite(&num, sizeof(struct nomor), 1, fptr);
//     }
//     printf("Berhasil menulis file!\n");
//     fclose(fptr);

//     struct nomor buff;
//     fptr = fopen("program.bin", "rb");
//     printf("Isi dalam file: \n");
//     while (fread(&buff, sizeof(struct nomor), 1, fptr))
//     {
//     printf("n1= %d\t n2=%d\t n3=%d\n", buff.n1, buff.n2, buff.n3);
//     }
//     fclose(fptr);
// }


