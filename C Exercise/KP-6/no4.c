#include <stdio.h>

void kuadrat(int* bil, int size){
    for (int i = 0; i < size; i++)
    {
        bil[i]*=bil[i];
    }
}

int main(){
    int bil[] = {2, 4, 5, 6};
    int size = sizeof(bil)/sizeof(bil[0]);
    kuadrat(bil, size);
    for (int i = 0; i < size; i++)
    {
    printf("%d ", bil[i]);
    }
    
    return 0;
}
