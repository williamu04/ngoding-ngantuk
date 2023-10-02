#include <bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;
    vi X(N);
    loop(i,N){
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    loop(i, 10) {
        loop(j, N) {
             if (X[j]%10 == i) {
                 cout << X[j] << "\n";
            }
        }  
    }
}