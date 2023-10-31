#include <stdio.h>
#include <math.h>

int main(){
    int p1=70, p2=50, l1=15, l2=15, t1=15, t2=20;
    int luas1 = (p1*l1)+(p1*t1*2)+(l1*t1*2)+((p1-p2)*l1);
    int luas2 = (l2*t2)+(p2*t2)+((sqrt(p2*p2 - l2*l2)*p2));
    printf("Luas permukaan bangun itu adalah: %d cm^2", luas1+luas2);
}