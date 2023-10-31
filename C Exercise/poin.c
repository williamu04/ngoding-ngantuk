#include <stdio.h>

void kurang_poin(int *po_ptr, int jml){
    *po_ptr -= jml;
}

int main(){
    int poin = 250;

    printf("Poin awal : %d\n", poin);

    kurang_poin(&poin, 76);

    printf("Poin saat ini: %d\n", poin);

    return 0;
}