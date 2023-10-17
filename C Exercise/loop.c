#include <stdio.h>

int main(){
    int i=0;
    for (i=0; i<=10; i++){
        printf("ini adalah yang ke %d\n", i);
        if (i == 5){
            i++;
            break;
        }
    }
    while (i>5)
    {
        printf("sedangkan ini adalah yang ke %d\n", i);
        if (i == 10){
            break;
        }
        i++;
    }
    return 0;
}