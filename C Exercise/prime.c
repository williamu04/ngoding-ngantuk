#include <stdio.h>

int main(){
    int n = 7, stat;

    if(n <= 1) {
        printf("Masukkan angka lebih dari 1.");
    } else {
        if(n == 2){
        printf("%d merupakan bilangan prima.", n);
        } else {
            for(int angka=2; angka < n; angka++){
                if(n%angka == 0){
                    stat = 0;
                    break;
                } else {
                    stat = 1;
                }
            }
            if(stat == 0){
                printf("%d bukan bilangan prima.\n", n);
            } else {
                printf("%d merupakan bilangan prima.", n);
            }
        }
    }
}