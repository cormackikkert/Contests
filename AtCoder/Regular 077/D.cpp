#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD = 1e9 + 7;

using vc = vector<char>;
using vi = vector<int>;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vi seen (N, -1);

    int C1, C2;

    F0R(i, N+1) {
        int a; cin >> a; --a;
        if (seen[a] != -1) {
            C1 = seen[a]; C2 = i; break;
        } else {
            seen[a] = i;
        }
    }

    ll ans;
    ans += binpow(2, C1) * binpow(2, N-1-C2); ans %= MOD;
    ans += binpow(2, N-1); ans %= MOD;
    ans += binpow(2, N-2); ans %= MOD;
    ans += binpow(2, N-2); ans %= MOD;
    cout << ans << endl;
}