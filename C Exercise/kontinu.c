#include <stdio.h>

int main(){
    for (int i=0; i<10; i++){
        printf("ini adalah %d\n", i);
        if (i == 4)
        {
            i++;
            printf("hey aku adalah %d\n", i);
            continue;
        }
    }
    return 0;
}