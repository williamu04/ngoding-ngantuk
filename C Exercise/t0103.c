#include <stdio.h>
#define pi 3.14

int main(){
    float rt = 10.5, tt = 5, rk = 4, tk = 4.7;
    float lt = pi*rt*rt*tt;
    float lk = pi*rk*rk*tk/3;

    printf("volume tabung adalah = %.2f cm^3\nvolume kerucut adalah = %.2f cm^3\nair yang tumpah adalah = %.2f cm^3", lt, lk, lk);
    return 0;
}