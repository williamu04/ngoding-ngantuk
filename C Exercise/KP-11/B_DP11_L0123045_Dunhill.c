#include <stdio.h>
#include <string.h>

#define MAX 255

// struct dengan nama Data untuk menyimpan biodata
typedef struct 
{
    char nama[MAX];
    char alamat[MAX];
    char lulusan[MAX];
    int umur;
    float ipk;
} Data;

// fungsi intro untuk membuat file  intro.txt yang menyimpan teks perkenalan
void intro(Data *data){
    FILE *file;
    file = fopen("intro.txt", "w");
    if (file == NULL)
    {
        perror("Tidak bisa membuat file");
        return;
    }
    fprintf(file, "Halo, nama saya %s, ", data->nama);
    fprintf(file, "saat ini saya berdomisili di %s. ", data->alamat);
    fprintf(file, "Saya berumur %d tahun, ", data->umur);
    fprintf(file, "lulus dari %s dengan IPK %.2f.", data->lulusan, data->ipk);
    fclose(file);
}

int main(){
    Data data;
    printf("===[ Template Perkenalan Diri ]===\n");
    printf("Masukkan data diri anda di bawah ini:\n");
    
    //Input user
    printf("Nama    : ");
    fgets(data.nama, MAX, stdin); 
    data.nama[strcspn(data.nama, "\n")] = 0;
    printf("Alamat  : ");
    fgets(data.alamat, MAX, stdin);
    data.alamat[strcspn(data.alamat, "\n")] = 0;
    printf("Lulusan : ");
    fgets(data.lulusan, MAX, stdin);
    data.lulusan[strcspn(data.lulusan, "\n")] = 0;
    printf("Umur    : ");
    scanf("%d", &data.umur);
    printf("IPK     : ");
    scanf("%f", &data.ipk);
    printf("\n");

    //passing struct data ke funsi intro
    intro(&data);

    printf("===[ Teks perkenalan anda disimpan dalam file intro.txt ]===\n");
    printf("Berikut teks perkenalan anda: \n");

    //membaca file intro.txt
    FILE *file = fopen("intro.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
    }
    
    char buff[MAX];
    while(fgets(buff, MAX, file)){
       printf("%s", buff);
    }
    fclose(file);

    return 0;
}
