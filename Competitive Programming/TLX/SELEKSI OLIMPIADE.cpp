#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

struct Peserta {
  string id; 
  int s1, s2, s3; 
};

bool cmp(Peserta a, Peserta b) {
  if (a.s3 != b.s3) return a.s3 > b.s3;
  if (a.s2 != b.s2) return a.s2 > b.s2;
  return a.s1 > b.s1;
}

int main() {
  int T;   
  cin >> T;
  while (T--) {
    int N, M; 
    string target; 
    cin >> N >> M >> target;
    vector<Peserta> v(N); 
    loop(i, N) {
      cin >> v[i].id >> v[i].s1 >> v[i].s2 >> v[i].s3; 
    }
    sort(v.begin(), v.end(), cmp); 
    bool lulus = false; 
    loop(i, M) {
      if (v[i].id == target) { 
        lulus = true;
        break;
      }
    }
    if (lulus) cout << "YA\n"; 
    else cout << "TIDAK\n"; 
  }
}