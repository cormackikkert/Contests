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

vector<vll> dp;

vi NS;
vi MS;

ll recurse(int n, int m) {
    if (n == -1 || m == -1) return 1;

    if (dp[n][m] != -1) return dp[n][m];

    ll total = 0;
    if (NS[n] == MS[m]) 
        total += 2 * recurse(n-1, m-1);
    else 
        total += recurse(n-1, m-1);
    total %= MOD;
    total += recurse(n-1, m) - recurse(n-1, m-1);   total %= MOD;
    total += recurse(n, m-1) - recurse(n-1, m-1);   total %= MOD;
    dp[n][m] = total;
    return total;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin >> N >> M;

    NS = vi (N);
    F0R(i, N) cin >> NS[i];

    MS = vi (M);
    F0R(i, M) cin >> MS[i];

    dp = vector<vll> (N, vll (M, -1));

    cout << (MOD + recurse(N-1, M-1)) % MOD << endl;
}