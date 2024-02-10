#include <stdio.h>
#include <string.h>

typedef enum {
    mahasiswa,
    dosen,
    tendik
} e;

e keString(char *s){
    if(strcmp(s, "mahasiswa")==0) return mahasiswa;
    else if(strcmp(s, "dosen")==0) return dosen;
    else if(strcmp(s, "tendik")==0) return tendik;
}

struct mahasiswa 
{
    char nama[50];
    int nim;
    char email[50];
};

struct dosen 
{
    char nama[50];
    int nidn;
    char email[50];
};

struct tendik
{
    char nama[50];
    int nik;
    char email[50];
    char unit[50];
};

typedef union
{
    struct mahasiswa mhs;
    struct dosen dsn;
    struct tendik tnd;
} c;


typedef struct 
{
    e tipe;
    c stat;
}civ;


int main(){
    int n;
    printf("Masukkan jumlah data yang ingin diinput: ");
    scanf("%d", &n);

    civ kerja[n];
    char civi[15];
    
    for (int i = 0; i < n; i++)
    {
        printf("Data-%d\n", i+1);
        printf("Jenis civitas: ");
        scanf("%s", civi);
        kerja[i].tipe = keString(civi);
        switch (kerja[i].tipe)
        {
        case mahasiswa:
            printf("Nama  : ");
            scanf("%s", kerja[i].stat.mhs.nama);
            printf("Nim   : ");
            scanf("%d", &kerja[i].stat.mhs.nim);
            printf("Email : ");
            scanf("%s", kerja[i].stat.mhs.email);
            break;
        case dosen:
            printf("Nama  : ");
            scanf("%s", kerja[i].stat.dsn.nama);
            printf("Nidn  : ");
            scanf("%d", &kerja[i].stat.dsn.nidn);
            printf("Email : ");
            scanf("%s", kerja[i].stat.dsn.email);
            break;
        case tendik:
            printf("Nama  : ");
            scanf("%s", kerja[i].stat.tnd.nama);
            printf("Nik   : ");
            scanf("%d", &kerja[i].stat.tnd.nik);
            printf("Email : ");
            scanf("%s", kerja[i].stat.tnd.email);
            printf("Unit  : ");
            scanf("%s", kerja[i].stat.tnd.unit);
            break;
        default:
            break;
        }
    }

    printf("\n\nInformasi\n-----------\n");

  for (int i = 0; i < n; i++)
    {
        printf("Data-%d\n", i+1);
        switch (kerja[i].tipe)
        {
        case mahasiswa:
            printf("Nama  : %s\n", kerja[i].stat.mhs.nama);
            printf("Nim   : %d\n", kerja[i].stat.mhs.nim);
            printf("Email : %s\n", kerja[i].stat.mhs.email);
            break;
        case dosen:
            printf("Nama  : %s\n", kerja[i].stat.dsn.nama);
            printf("Nidn  : %d\n", kerja[i].stat.dsn.nidn);
            printf("Email : %s\n", kerja[i].stat.dsn.email);
            break;
        case tendik:
            printf("Nama  : %s\n", kerja[i].stat.tnd.nama);
            printf("Nik   : %d\n", kerja[i].stat.tnd.nik);
            printf("Email : %s\n", kerja[i].stat.tnd.email);
            break;
        default:
            break;
        }
    }   
    
}