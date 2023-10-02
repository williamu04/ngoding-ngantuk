#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

    vector<int> dp(N, 1);

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] < arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, dp[i]);
  }
    cout << ans << endl;

  return 0;
}
