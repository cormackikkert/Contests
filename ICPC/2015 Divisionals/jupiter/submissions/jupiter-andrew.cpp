// AC
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

bool wins(char a, char b) {
  return (a == 'R' && b == 'S')
      || (a == 'S' && b == 'P')
      || (a == 'P' && b == 'R');
}
map<char,char> mp = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

int n, k, l, m;
string A, B;

int result(int x, int y, int z) {
  string sA = A.substr(x, k);
  string sB = B.substr(y, k);
  for (int i = 0; i < k; i++)
    if (z <= i && i < z + l) sA[i] = mp[ sA[i] ];

  int wA = 0, wB = 0;
  REP(i,k) {
    if (wins(sA[i],sB[i])) wA++;
    if (wins(sB[i],sA[i])) wB++;
    if (wA >= m) return 1;
    if (wB >= m) return -1;
  }
  return 0;
}

int solve() {
  int ans = -1;
  REP(x,n-k+1) {
    int ans1 = 1;
    REP(y,n-k+1) {
      int ans2 = -1;
      REP(z,k-l+1) {
        //cout << x << " " << y << " " << z << " " << result(x,y,z) << endl;
        ans2 = max(ans2, result(x,y,z));
      }
      ans1 = min(ans1, ans2);
    }
    ans = max(ans, ans1);
  }
  return ans;
}

map<int,string> outp = {{1, "Alice"}, {-1, "Bob"}, {0, "Draw"}};
int main() {
  cin >> n >> k >> l >> m >> A >> B;
  cout << outp[solve()] << endl;
}
