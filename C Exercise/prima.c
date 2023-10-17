#include <stdio.h>

int main(){
    int n = 1000;

    for (int i = 0; i < n; i++)
    {
        if (i == 2)
        {
            printf("%d", i);
        } else {
            for (int j = 0; j < i/2; j++)
            {
                if (i%j == 1)
                {
                    printf("%d", i);
                }
            }
        }
    }
}