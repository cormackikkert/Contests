#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD = 1e9+7;

using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

const ll MAXN = 200002;

vll fact (MAXN);
vll inv (MAXN);
vll invfact (MAXN);

ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll H, W, A, B; cin >> H >> W >> A >> B;

    fact[0] = 1;
    FOR(i, 1, MAXN) fact[i] = fact[i-1] * i % MOD;

    inv[1] = 1;
    FOR(i, 2, MAXN) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

    invfact[0] = 1;
    FOR(i, 1, MAXN) invfact[i] = invfact[i-1] * inv[i] % MOD;

    ll ans = 0;
    ll rekt = 0;
    F0R(i, H - A) {
        ans = (ans + (choose(B + i, B) - rekt) * choose(H - i - 1 + W - B - 1, W - B - 1) % MOD) % MOD;
        rekt += choose(B + i, B) - rekt; 
    }
    cout << (ans + MOD) % MOD<< endl;
}