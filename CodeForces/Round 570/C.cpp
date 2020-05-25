#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, l, r) for (ll i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll
 
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll q; cin >> q;
    for (ll t = 0; t < q; ++t) {
        ll k, n, a, b; cin >> k >> n >> a >> b;
        ll best = -1;
        ll l = -1; ll h = n;
        while (l < h) {
            ll m = l + (h - l + 1) / 2;
            if (k - a * m - b * (n - m) > 0) {
                l = m;
            } else {
                h = m - 1;
            }
        }
        cout << l << endl;
    }
}