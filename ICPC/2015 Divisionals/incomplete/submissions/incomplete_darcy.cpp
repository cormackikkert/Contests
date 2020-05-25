#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,d;
  cin >> k >> d;

  int books = 0;
  while(k <= d) {
    books++;
    d -= k;
    k *= 2;
  }
  cout << books << endl;
}
