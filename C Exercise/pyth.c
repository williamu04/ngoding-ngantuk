#include <stdio.h>
#include <math.h>
#define pi 3.1415

int isPyth(long a, long b, long c){
    if (c*c == a*a + b*b){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int a, b, c;
    printf("Masukkan sisi depan: ");
    scanf("%d", &a);
    printf("Masukkan sisi samping: ");
    scanf("%d", &b);
    printf("Masukkan sisi miring: ");
    scanf("%d", &c);
    printf("%s", isPyth(a,b,c) ? "Adalah segitiga pytagoras" : "Bukan segitia pytagoras");
}

// float hipotenusa(float a, float rad){
//     return a/sin(rad*pi/180);
// }

// float panjangAB(float b, float rad){
//     return b/tan(rad*pi/180);
// }

// int main(){
//     printf("%f\n", hipotenusa(4, 30));
//     printf("%f", panjangAB(4, 30));

// }

// #include <stdio.h>
// #include <math.h>

// int Sisi_A, Sisi_B, Sisi_C;
// void Apakah_Pitagoras(int Sisi_A, int Sisi_B, int Sisi_C);

// int main() {
//     printf("Masukkan Sisi A (sisi terpanjang): "); 
//     scanf("%d", &Sisi_A);

//     printf("Masukkan Sisi B: "); 
//     scanf("%d", &Sisi_B);

//     printf("Masukkan Sisi C: ");
//     scanf("%d", &Sisi_C);

//     Apakah_Pitagoras(Sisi_A, Sisi_B, Sisi_C); 
// }

// void Apakah_Pitagoras(int Sisi_A, int Sisi_B, int Sisi_C) {
//     if (pow(Sisi_A, 2) == pow(Sisi_B, 2) + pow(Sisi_C, 2)) { 
//         printf("Iya, segitiga %d %d %d adalah segitiga Pitagoras\n", Sisi_A, Sisi_B, Sisi_C);
//     } else {
//         printf("Bukan, segitiga %d %d %d bukan segitiga Pitagoras\n", Sisi_A, Sisi_B, Sisi_C);
//     }
// }