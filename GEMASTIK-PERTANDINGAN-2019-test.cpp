#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

int skill_max(int N, int M, vi A, vi B){
    vpi AB;
    loop(i, N){
        AB.push_back(make_pair(A[i], B[i]));
    }
    sort (AB.begin(), AB.end());

    int keahlian = M;
    loop(i, N){
        if (keahlian >= AB[i].first){
            keahlian += AB[i].second;
        } else {
            break;
        }
    }
    return keahlian;
}

int main(){
    int N, M;
    cin >> N >> M;
    vi A(N), B(N);
    loop(i, N) {
        cin >> A[i];
    }
    loop(i, N){
        cin >> B[i];
    }
    cout << skill_max(N, M, A, B) <<endl;
    return 0;
}