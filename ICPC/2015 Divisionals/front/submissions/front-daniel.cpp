// Daniel's first Solution
// Expected Verdict: AC
//
// Solving time:
//   Reading problem and realising DP: 2 minutes
//   Re-reading, verifying idea and making sure bounds are fine: 5 minutes
//   Coding recurrence on paper: 3 minutes
//   TOTAL: 10 minutes
//
// Implementation time:
//   Initial implementation with bugs: 8 minutes
//   Finding and fixing bugs: 8 minutes
//   TOTAL: 16 minutes
//
// Thoughts about the problem statement:
//  - I think that talking about the "hole" could be confusing
//    to non-native speakers. They might imagine the actual
//    hole that the ball goes in being n units long!
//  - The function notation might confuse some people.
//
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define debug(a) cerr << #a << " = " << (a) << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
	int b=0; for (const auto& a : v) o << (b++ ? " " : "") << a; return o;
}

int n, h, a, Pdown, Pmid, Pup;

int fix(int y) {
  return min(h, max(0, y));
}

double DP[102][100010]{};

double f(int x, int y) {
  if (x == n) return 0.0;
  if (DP[y][x] > -0.5) return DP[y][x];
  double& ans = DP[y][x] = y;
  ans += Pdown / 100.0 * (f(x+1,fix(y-1)) - (y > 0 ? 0.5 : 0.0));
  ans += Pmid / 100.0 * f(x+1,y);
  ans += Pup / 100.0 * (f(x+1,fix(y+1)) + (y < h ? 0.5 : 0.0));
  return ans;
}

int main() {
  ios::sync_with_stdio(0);  cin.tie(0);
  cin >> n >> h >> a >> Pdown >> Pmid >> Pup;
  for (int i=0;i<102;i++) for(int j=0; j<100010; j++) DP[i][j] = -1.0;
  cout << fixed << setprecision(20) << f(0, a) << '\n';
}
