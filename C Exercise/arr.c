#include <stdio.h>

int main(){
    int nilaiMhs[][100] = {
        {10, 20, 30, 40, 50},
        {11, 21, 31, 41, 51},
        {12, 22, 32, 42, 52},
        {13, 23, 33, 43, 53},
        {14, 24, 34, 44, 54}
    };

    int x = sizeof(nilaiMhs)/sizeof(nilaiMhs[0]);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; i++)
        {
            printf("%d " ,nilaiMhs[i][j]);
        }
        printf("\n");
    }
}