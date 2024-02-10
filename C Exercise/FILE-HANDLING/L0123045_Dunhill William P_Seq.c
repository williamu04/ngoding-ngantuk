#include <stdio.h>

int main() {
    FILE *file;
    int n;
    char str[255];
    printf("Masukkan banyak n kata: ");
    scanf("%d", &n);
    printf("Buat sebuah kalimat terdiri dari n kata:\n");

    file = fopen("sample.txt", "w");
    if (file == NULL)
    {
        printf("Tidak bisa membuat file");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d-", i+1);
        scanf("%s", str);
        fprintf(file, "%s ", str);
    }
    fclose(file);

    file = fopen("sample.txt", "r");
    if (file == NULL)
    {
        printf("Tidak bisa membuka file");
        return 1;
    }

    char buff[255];
    printf("Isi dalam file sample: \n");
    while (fgets(buff, 255, file))
    {
        printf("%s", buff);
    }
    fclose(file);
    return 0;
}
