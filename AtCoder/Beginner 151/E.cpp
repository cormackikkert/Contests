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
using vll = vector<ll>;

vll fact, inv, invfact;

ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, K;
    cin >> N >> K;

    fact = vll (N+1);
    fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = fact[i-1] * i % MOD;

    inv = vll (N+1);
    inv[1] = 1;
    FOR(i, 2, N+1) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

    invfact = vll (N+1);
    invfact[0] = 1;
    FOR(i, 1, N+1) invfact[i] = invfact[i-1] * inv[i] % MOD;

    vll arr (N);
    F0R(i, N) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    ll BM = 0;
    FOR(i, K-1, N) {
        BM += arr[i] * choose(i, K-1);
        BM %= MOD;        
    }

    ll BS = 0;
    FOR(i, 0, N-K+1) {
        BS += arr[i] * choose(N-i-1, K-1);
        BS %= MOD;
    }
    cout << (BM - BS + MOD) % MOD << endl;
}