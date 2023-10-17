#include <stdio.h>
#define pi 3.14

int main(){
    int r1 = 10, r2 = 12, r3 = 14;

    float l1 = pi*r1*r1;
    float l2 = pi*r2*r2;
    float l3 = pi*r3*r3;

    printf("luas lingkaran a = %.2f cm^2\nluas lingkaran b = %.2f cm^2\nluas lingkaran c = %.2f cm^2\nluas yang diarsir adalah = %.2f cm^2", l1, l2, l3, l3-l2+l1);
    return 0;
}