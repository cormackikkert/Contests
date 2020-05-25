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
    int N, K1, K2; cin >> N >> K1 >> K2;
    int M1 = 0;
    int M2 = 0;
    F0R(i, K1) {int a; cin >> a; M1 = max(M1, a);}
    F0R(i, K2) {int a; cin >> a; M2 = max(M2, a);}
    cout << ((M1 > M2) ? "YES" : "NO") << '\n';
    
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    F0R(i, T) solve();
}