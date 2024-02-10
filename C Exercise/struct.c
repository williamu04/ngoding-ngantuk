#include <stdio.h>

struct hero
{
    char name[25];
    int power;
    int health;
    int exp;
};

int main(){
    
    int arr[4] = {1000, 2000, 3000, 4000};
    int n = 0;
    for (int i = 0; i < 4; i++)
    {
       printf("%p", *arr);
    }

}
