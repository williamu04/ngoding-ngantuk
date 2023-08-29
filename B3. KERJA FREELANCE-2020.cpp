#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
    int mulai, selesai, upah;
};

bool compare(job a, job b){
    if (a.selesai < b.selesai){
        return 1;
    } else return 0;
}

int cariMax(int array[], int n, int x){
    int L=0;
    int R=n;

    while (L <= R)
    {
        int M = L + (R-L)/2;
        if (array[M] >= x){
            R = M-1;
        } else {
            if (array[M+1] >= x){
                return M;
            } else { 
                L = M+1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    job pekerjaan[n+1];
    pekerjaan[0].mulai = 0;
    pekerjaan[0].selesai = 0;
    pekerjaan[0].upah = 0;
    for (int i=1; i <= n; i++){
        cin >> pekerjaan[i].mulai >> pekerjaan[i].selesai >> pekerjaan[i].upah;
    }
    sort (pekerjaan, pekerjaan+(n+1), compare);

    int finish[n+1];
    for (int i=0; i<=n; i++){
        finish[i] = pekerjaan[i].selesai;
    }

    int maxUpah[n+1];
    maxUpah[0] = 0;

    for (int i=1; i<=n; i++){
        int skip = maxUpah[i-1];
        int kerjain = pekerjaan[i].upah;
        int k = cariMax(finish, n, pekerjaan[i].mulai);
        kerjain = maxUpah[k] + pekerjaan[i].upah; 
        maxUpah[i] = max(skip, kerjain);
    }
    cout << maxUpah[n];

    return 0;
}
