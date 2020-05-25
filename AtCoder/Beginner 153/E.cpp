#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll H, N;
    cin >> H >> N;
    vi AS (N);
    vi BS (N);
    F0R(i, N) {
        cin >> AS[i] >> BS[i];
    }

    vi dp (H+1);
    F0R(i, H+1) dp[i] = -1;
    dp[0] = 0;
    FOR(i, 0, H) {
        F0R(j, N) {
            if (AS[j] < i) continue;
            if (dp[i] == -1) dp[i] = BS[j];
            else dp[i] = min(BS[j], dp[i]);
        }
        if (dp[i] == -1) continue;
        F0R(j, N) {
            if (i + AS[j] > H) continue;
            if (dp[i+AS[j]] == -1) dp[i+AS[j]] = dp[i] + BS[j];
            else dp[i+AS[j]] = min(dp[i+AS[j]], dp[i] + BS[j]);
        }
    
    }

    F0R(j, N) {
        if (AS[j] < H) continue;
        if (dp[H] == -1) dp[H] = BS[j];
        else dp[H] = min(BS[j], dp[H]);
    }

    cout << dp[H] << endl;
}