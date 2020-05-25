#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

unordered_set<ll> arr;

ll recurse(ll pos, ll dig) {
    if (dig < 0) return 0;
    if (arr.find(pos) == arr.end()) return 0;

    ll best = INF;
    // place 0
    ll res1 = recurse(2*pos, dig-1);
    ll res2 = recurse(2*pos+1, dig-1);

    best = min(best, max((arr.find(2*pos+1) != arr.end()) * (1 << dig) + res2, res1));
    best = min(best, max((arr.find(2*pos) != arr.end()) * (1 << dig) + res1, res2));
    return best;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    arr.insert(1);
    F0R(j, N) {
        ll pos = 1;
        ll val; cin >> val;
        R0F(i, 30) {
            if (((val >> i) & 1) > 0) {
                pos = 2 * pos + 1;
            } else {
                pos = 2 * pos;
            }
            arr.insert(pos);
        }
    }

    cout << recurse(1, 29) << endl;
}