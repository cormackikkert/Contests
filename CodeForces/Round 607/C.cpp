#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)


ll INF = 1LL << 60;
ll MOD = 1e9+7;

using vc = vector<char>;
using vi = vector<int>;

void solve() {
    ll x; cin >> x;
    string s; cin >> s;

    ll size = s.length();
    ll onRight = size - 1;
    F0R(i, x) {
        if (onRight == 0) break;
        ll times = s.at(i) - '1';
        if (s.size() <= x) {
            string right = s.substr(i+1, x - s.size());
            F0R(j, times) s+=right;
        }
        
        F0R(j, times) {
            size += onRight;
            size %= MOD;
        }
        ll copy = onRight;
        F0R(j, times) {
            onRight += copy;
            onRight %= MOD;
        }
        onRight = (MOD + onRight - 1) % MOD;
    }
    cout << size << endl;

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t; cin >> t;
    F0R(i, t) solve();
}