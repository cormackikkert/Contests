#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, double> atoms;
  for (int i = 0; i < N; ++i) {
    string name;
    double w;
    cin >> name >> w;
    atoms[name] = w;
  }

  string mol;
  cin >> mol;

  double ans = 0;
  int i = 0;
  while (i < mol.size()) {
    string elem, num;
    elem.push_back(mol[i++]);
    while (i < mol.size() && !isupper(mol[i]) && !isdigit(mol[i])) {
      elem.push_back(mol[i++]);
    }
    while (i < mol.size() && isdigit(mol[i])) {
      num.push_back(mol[i++]);
    }
    if (num == "")
      num = "1";
    ans += atoms[elem]*strtoll(num.c_str(), nullptr, 10);
  }
  cout << fixed << setprecision(20) << ans << endl;
}
