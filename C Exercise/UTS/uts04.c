#include <stdio.h>
#include <math.h>
int main(){
    int jam1, jam2, mnt1, mnt2, dtk1, dtk2;
    char jenis[10];

    printf("Jam masuk: ");
    scanf("%d %d %d", &jam1, &mnt1, &dtk1);
    printf("Jam keluar: ");
    scanf("%d %d %d", &jam2, &mnt2, &dtk2);
    printf("Jenis kendaraan: ");
    scanf("%s", jenis);
    
    int dur_jm = jam2-jam1;
    int dur_mn = mnt2-mnt1;
    int dur_dt = dtk2-dtk1;
    
    if (dur_mn > 0){
        dur_jm+=1;
    } else if (dur_dt > 0){
        dur_jm+=1;
    }

    int tot;
    if (dur_jm > 2){
        tot = 2000+(dur_jm-2)*500;
    } else {
        tot = dur_jm*1000;
    }
    if (jenis == "motor"){
        if (tot > 7500) return 7500;
        else return tot;
    } else if (jenis == "mobil"){
        if (tot > 15000) return 15000;
        else return tot;
    }
    printf("Durasi parkir: %d\n", dur_jm);
    printf("Biaya parkir: %d", tot);
}