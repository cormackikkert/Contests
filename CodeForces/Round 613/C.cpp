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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll X; cin >> X;
    ll best = X;
    for (ll x = 1; x * x <= X; ++x) {
        // cout << x << endl;
        if (X % x != 0) continue;
        ll y = X / x;

        // cout << x * y << " " << __gcd(x, y) << endl;
        if (x * y / __gcd(x, y) == X) {
            best = min(best, max(x, y));
        }
    }
    cout << best << " " << X / best << endl;
}