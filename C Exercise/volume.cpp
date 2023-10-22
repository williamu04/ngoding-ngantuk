#include <iostream>
using namespace std;
#define pi 3.14

float volume (float r, float t);

main(){
    cout << volume(7, 1);
    return 0;
}

float volume (float r, float t) {
    return r*r*t*pi;
}