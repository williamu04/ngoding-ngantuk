#include <stdio.h>
#include <math.h>
#define a 53
#define g 9.8
#define pi 3.14

int main(){
    float vo = 30;
    float xmax = vo*vo*sin(2*a*pi/180)/g;  
    printf("jarak awal dengan lobang golf adalah = %.1f m", xmax);
    return 0;
}


