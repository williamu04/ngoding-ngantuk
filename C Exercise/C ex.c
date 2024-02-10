#include <stdio.h>
#define loop(i,n) for(int i=0; i<n; i++)

int main(){
    loop(i, 5){
        printf("%d\n", i);
    }
}