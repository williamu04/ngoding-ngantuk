#include <stdio.h>
#include <string.h>

void sortStringByChar(char data[][20], int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (strlen(data[i]) < strlen(data[j]))
            {
                char temp[20];
                strcpy(temp, data[i]);
                strcpy(data[i], data[j]);
                strcpy(data[j], temp);
            }
        }
    }
}

int main(){
    char data[3][20] = {"rambutan", "apel", "jeruk"};
    int len = sizeof(data)/sizeof(data[0]);

    sortStringByChar(data, len);

    for(int i = 0; i < len; i++){
        printf("%s ", data[i]);
    }

    return 0;
}
