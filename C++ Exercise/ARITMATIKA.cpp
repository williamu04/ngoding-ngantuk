#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> guests(N);

  for (int i = 0; i < N; i++) {
    cin >> guests[i];
  }

  sort(guests.begin(), guests.end());

  for (int i = 0; i < N; i++) {
    cout << guests[i] << endl;
  }
  return 0;
}
