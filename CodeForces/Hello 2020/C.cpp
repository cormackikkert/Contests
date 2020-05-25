#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD;

using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

vll fact;

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

ll inverse(ll n) {
    return binpow(n, MOD-2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N;

    cin >> N >> MOD;

    fact.resize(N+1); fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = fact[i-1] * i % MOD;

    ll ans = 0;

    FOR(K, 1, N+1) {
        ans += (N-K+1) * (N-K+1) % MOD * fact[K] % MOD * fact[N-K] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}