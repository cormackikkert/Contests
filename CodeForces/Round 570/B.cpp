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
    for (ll i = 0; i < q; ++i) {
        ll n, k; cin >> n >> k;
        ll l = INF; ll h = 0;
        for (ll j = 0; j < n; ++j) {
            ll p; cin >> p;
            l = min(l, p); h = max(h, p);
        }
        if (h - k <= l + k) {
            cout << l + k << endl;
        } else {
            cout << -1 << endl;
        }
    }
}