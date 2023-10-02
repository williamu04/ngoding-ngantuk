#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

struct peserta
{
    string id;
    int s1, s2, s3;
};

bool urut(peserta a, peserta b){
    if (a.s3 != b.s3) return a.s3 > b.s3;
    if (a.s2 != b.s2) return a.s2 > b.s2;
    return a.s1 > b.s1;
}

int main() {
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        string target;
        cin >> N >> M >> target;
        vector<peserta> v(N);
        loop(i, N) {
            cin >> v[i].id >> v[i].s1 >> v[i].s2 >> v[i].s3;
        }
        sort(v.begin(), v.end(), urut);
        bool hasil = false;
        loop(i, M){
            if(v[i].id == target){
                hasil = true;
                break;
            }
        }
        if (hasil) cout << "YA";
        else cout << "TIDAK";
    }
    
}
