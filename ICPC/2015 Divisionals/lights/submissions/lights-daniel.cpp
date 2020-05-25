#include <iostream>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  for (int i=0; i<N; i++) {
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    if (x < a || (x - a) % (b + c) > b) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
