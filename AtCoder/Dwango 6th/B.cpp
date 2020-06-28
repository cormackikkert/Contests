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
    ll N; cin >> N;
    vll arr (N);
    F0R(i, N) cin >> arr[i];
    vll cumsum (N+1);
    cumsum[N] = arr[N-1];
    ROF(i, 1, N) cumsum[i] = cumsum[i+1] + arr[i-1];
    
    vll fact (N+1);
    fact[0] = 1;
    FOR(i, 1, N+1) {fact[i] = fact[i-1] * i % MOD;}

    ll ans = 0;
    FOR(i, 1, N-1) {
        ans += cumsum[i+2] - (N - 1 - i) * arr[i];
        ans %= MOD;
    }
    cout << (ans * fact[N-2] % MOD + (arr[N-1] - arr[0]) * fact[N-1] % MOD) % MOD << endl;
}
