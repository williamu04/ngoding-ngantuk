#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *arr, int n){
    bool koentji;

    for (int i = 0; i < n; i++)
    {
        koentji = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                koentji = true;
            }
        }
        if (koentji == false)
        {
            break;
        }
    }
}

int main(){
    int n;
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    int k[n]; 
    for (int i = 0; i < n; i++) 
    {
        printf("Bilangan ke-%d : ", i+1); 
        scanf("%d", &k[i]); 
    }
    
    bubbleSort(k, n);
    printf("Bilangan yang berurutan adalah: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", k[i]);
    }    
}
