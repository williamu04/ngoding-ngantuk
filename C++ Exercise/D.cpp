#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string start, end;
  cin >> start >> end;

  int rotations = 0;

  for (int i = 0; i < start.length(); i++) {
    int s = start[i] - '0';
    int e = end[i] - '0';
    int diff = abs(s - e);
    rotations += min(diff, 10 - diff);
  }

  cout << rotations << endl;

  return 0;
}
