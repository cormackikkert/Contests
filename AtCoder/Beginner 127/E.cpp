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

ll BIG;

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


ll fact(ll n) {
    ll ans = 1;
    FOR(i, 1, n+1) {ans *= i; ans %= MOD;}
    return ans;
}

ll choose(ll n, ll k) {
    return fact(n) * inverse(fact(k)) % MOD * inverse(fact(n-k)) % MOD;
}

ll calc(ll N, ll M) {
    ll ans = 0;
    F0R(i, N - 1) {
        ll ED = (N - i);
        ans += ED * BIG % MOD * M % MOD * (N-i-1) % MOD * M % MOD;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, M, K; cin >> N >> M >> K;
    BIG = choose(N * M - 2, K - 2);
    ll ans = 0;
    ans += calc(N, M); ans %= MOD;
    ans += calc(M, N); ans %= MOD;
    cout << (ans * inverse(2)) % MOD << endl;
}