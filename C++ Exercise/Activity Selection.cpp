#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define loop(i,n) for(int i=1; i<n; i++)
#define loops(i, n) for(int i=0; i<n; i++)

struct akt
{
    int mulai;
    int selesai;
};

bool banding (akt a, akt b){
    return a.selesai < b.selesai;
}

int banyak (akt yes[], int n){ 
    if (n == 0) return 0;  
    sort(yes, yes+n, banding); 
    int i = 0; int counter = 1; 
    loop (j, n) { 
        if (yes[j].mulai >= yes[i].selesai){ 
            i = j; 
            counter++; 
        } 
    } return counter; 
}

int main() {
    int N;
    cin >> N;
    vector<akt> yes;
    loops(i, N){
        cin >> yes[i].mulai;
    } 
    loops(i, N){
        cin >> yes[i].selesai;
    }
    
    akt* arr = yes.data();
    int n = sizeof(arr)/sizeof(arr[0]); 
    int ans = banyak(arr, n); 
    cout << ans << endl;  
    return 0; 
}