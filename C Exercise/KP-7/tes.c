#include <stdio.h>

int i[10], x;
float f[10];
double d[10];

int main(){
    printf("\t\t  Integer\t\t  Float\t\t\t  Double");
    printf("\n============================================================================");
    for (x = 0; x < 10; x++)
    {
        printf("\nElemen ke %d:\t%ld\t\t%ld\t\t%ld", x, &i[x], &f[x], &d[x]);
    }
    printf("\n============================================================================");
    return 0;
}



// ini no 3
// void swap(int *a, int *b, int *c);

// int main(){
//     int a, b, c;
//     printf("Masukkan nilai a, b, c berurutan: ");
//     scanf("%d %d %d", &a, &b, &c);
//     printf("Nilai sebelum ditukar: \n");
//     printf("a = %d \nb = %d \nc = %d\n", a, b, c);

//     swap(&a, &b, &c);
//     printf("Nilai setelah ditukar: \n");
//     printf("a = %d \nb = %d \nc = %d", a, b, c);
// }

// void swap(int *a, int *b, int *c){
//     int temp = *a;
//     *a = *b;
//     *b = *c;
//     *c = temp;
// }



// ini no 2
// int main(){
//     int data[5];
//     printf("Masukkan data: \n");
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", data+i);
//     }
    
//     printf("Nilai: \n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d\n", *(data+i));
//     }
//     return 0; 
// }


// ini nomor 1
// int main(){
//     int n, i;
//     float num[100], sum = 0.0, avg;
//     printf("Masukkan jumlah elemen: ");
//     scanf("%d", &n);

//     while (n > 100 || n < 1)
//     {
//         printf("Error!\n");
//         printf("Masukkan banyak elemen lagi: ");
//         scanf("%d", &n);
//     }
    
//     for (i = 0; i < n; i++)
//     {
//         printf("%d. Masukkan bilangan: ", i+1);
//         scanf("%f", &num[i]);
//         sum += num[i];
//     }

//     avg = sum/n;
//     printf("Rata-rata = %.2f", avg);
//     return 0;
// }