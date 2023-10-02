#include <stdio.h>

int main(){
    int A;
    printf("Berapa nilai A mu? ");
    scanf("%d", &A);

    if (A <= 10)
    {
        printf("Maka nilai A adalah ");
        printf("%d", A);
    } else {
        printf("Nilai A mu terlalu besar, nilai A mu ");
        printf("%d", A);
        printf(", jangan lebih dari 10!");
    }
    
}