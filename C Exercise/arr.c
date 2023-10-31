#include <stdio.h>

void tampilArray(char a[][10], int b[], int aL){
    printf("Data barang berikut:\n");
    for (int i = 0; i < aL; i++) {
        printf("%s : Rp %d\n", a[i], b[i]);
    }
}

int main(){
    char a[5][10] = {"kursi", "meja", "dipan", "sofa", "lemari"};
    int b[5] = {5000, 8000, 12000, 10000, 7000};

    tampilArray(a, b, 5);
    return 0;
}
