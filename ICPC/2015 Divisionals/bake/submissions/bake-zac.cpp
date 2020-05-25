// Expect AC - 200k x 256 should be ~ 5 . 10^7
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct Cake {
  int d, p, f = 0;
  bool b = true;
};

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<Cake> cakes(n);
  std::vector<int> latest(1<<6);
  int p = 1;
  for (int i = 0; i < n; ++i) {
    cakes[i].d = i+1;
    cakes[i].p = i+1;
  }
  for (int i = 0; i < 6; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < s.size(); ++j) if (s[j] == '1') {
      cakes[j].f |= (1<<i);
    }
  }
  std::vector<int> rs(m);
  for (int i = 0; i < 6; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < s.size(); ++j) if (s[j] == '1') {
      rs[j] |= (1<<i);
    }
  }
  std::sort(cakes.begin(), cakes.end(), [](const Cake &a, const Cake &b) {
    return a.d > b.d;
  });
  for (int i = 0; i < m; i++) {
    int f = rs[i];
    for (int j = latest[f]; j < n; j++) {
      if ((f & cakes[j].f) == f && cakes[j].b) {
        cakes[j].b = false;
        std::cout << cakes[j].p << " ";
        latest[f] = j + 1;
        goto EOL;
      }
    }
    std::cout << -1 << " ";
    EOL:;
  }
  std::cout << std::endl;
}
