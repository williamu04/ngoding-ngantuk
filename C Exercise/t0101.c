#include <stdio.h>

int main(){
    
    int n = 5; 
    int a[5] = {34, 56, 91, 11, 22};
    float p = 0;
    for (int i=0; i<n; i++){
        p += a[i];
    }
    printf("rata-rata 5 bilangan tersebut adalah = %.1f", p/n);

    return 0;
}