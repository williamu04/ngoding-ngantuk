#include <iostream>
using namespace std;

int fpb(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int P, Q, R, S;
  cin >> P >> Q >> R >> S;

  int X = P * S - Q * R;
  int Y = Q * S;

  int F = fpb(abs(X), abs(Y));
  X /= F;
  Y /= F;

  cout << X << " " << Y << endl;

  return 0;
}
