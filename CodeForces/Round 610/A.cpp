#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

void solve() {
    int x1, x2, c, r; cin >> x1 >> x2 >> c >> r;
    int a = min(x1, x2); int b = max(x1, x2);
    int ri = min(c + r, b);
    int le = max(c - r, a);
    if (c + r <= a || c - r >= b)
        cout << b - a << endl;
    else 
        cout << b - a - (ri - le) << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    F0R(i, t) solve();
}