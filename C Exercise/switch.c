#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand(time(NULL));

    int a[10] = {};

    for (int i = 0; i <= 10; i++)
    {
        a[i] = rand()%100 + 1;
    }
    
    int pilih;
    printf("pilih antara angka 1 - 10: ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        printf("ini adalah %d", a[1]);
        break;
    case 2:
        printf("ini adalah %d", a[2]);
        break;
    case 3:
        printf("ini adalah %d", a[3]);
        break;
    case 4:
        printf("ini adalah %d", a[4]);
        break;
    case 5:
        printf("ini adalah %d", a[5]); 
        break;
    case 6:
        printf("ini adalah %d", a[6]);    
        break;
    case 7:
        printf("ini adalah %d", a[7]);
        break;
    case 8:
        printf("ini adalah %d", a[8]);
        break;
    case 9:
        printf("ini adalah %d", a[9]);
        break;
    case 10:
        printf("ini adalah %d", a[10]);
        break;
    default:
        printf("YOOOOOOOOOOOOOOO");
        break;
    }
    return 0;
}