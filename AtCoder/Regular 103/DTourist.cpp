/**
 *    author:  tourist
 *    created: 29.09.2018 15:20:39       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<long long> d;
  vector<string> s(n, "");
  if ((x[0] & 1) == (y[0] & 1)) {
    d.push_back(1);
    for (int i = 0; i < n; i++) {
      s[i].push_back('U');
      y[i]--;
    }
  }
  long long step = 1;
  while (step < (1LL << 33)) {
    d.push_back(step);
    for (int i = 0; i < n; i++) {
      if ((x[i] & 1) == (y[i] & 1)) {
        cout << -1 << '\n';
        return 0;
      }
      if (x[i] & 1) {
        if (((x[i] - 1) & 2) != (y[i] & 2)) {
          x[i]--;
          s[i].push_back('R');
        } else {
          x[i]++;
          s[i].push_back('L');
        }
      } else {
        if (((y[i] - 1) & 2) != (x[i] & 2)) {
          y[i]--;
          s[i].push_back('U');
        } else {
          y[i]++;
          s[i].push_back('D');
        }
      }
      x[i] /= 2;
      y[i] /= 2;
    }
    step <<= 1;
  }
  d.push_back(step);
  for (int i = 0; i < n; i++) {
    assert(x[i] * x[i] + y[i] * y[i] == 1);
    s[i].push_back(x[i] == 1 ? 'R' : (x[i] == -1 ? 'L' : (y[i] == 1 ? 'U' : 'D')));
  }
  int m = (int) d.size();
  cout << m << '\n';
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << d[i];
  }              
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << s[i] << '\n';
  }
  return 0;
}
