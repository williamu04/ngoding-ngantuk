#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *ptr, sum = 0;

    printf("banyak bil: ");
    scanf("%d", &n);

    ptr = (int *) malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Eror");
        exit(0);
    }
    
    printf("Masukan nilai: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("Sum = %d", sum);
    free(ptr);
    ptr = NULL;
    return 0;
}