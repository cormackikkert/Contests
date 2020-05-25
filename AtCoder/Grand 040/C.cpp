#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD = 998244353;
 
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

const int MAXN = 1.01e7;

vll fact (MAXN);
vll invfact (MAXN);
vll pow2(MAXN);
vll inv (MAXN);

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

ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N; cin >> N;

    fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = fact[i-1] * i % MOD;

    inv[1] = 1;
    FOR(i, 2, MAXN) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
    
    invfact[0] = 1;
    FOR(i, 1, N+1) invfact[i] = invfact[i-1] * inv[i] % MOD;

    

    pow2[0] = 1;
    FOR(i, 1, N+1) pow2[i] = 2 * pow2[i-1] % MOD;

    ll ans = binpow(3, N);
    FOR(i, N/2+1, N+1) {
        ans -= 2 * choose(N, i) * pow2[N-i];
        ans = ((ans % MOD) + MOD) % MOD;
    }
    cout << ans << endl;
}