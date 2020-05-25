#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, H;
    cin >> N >> H;
    vector<bitset<10001>> dp (N + 1);

    vi w (N+1);
    vi h (N+1);
    FOR(i, 1, N+1) cin >> w[i] >> h[i];

    dp[0][0] = true;
    FOR(i, 1, N+1) {
        F0R(j, H+1) {
            dp[i][j] = dp[i][j] | dp[i-1][j];
            if (w[i] <= j)
                dp[i][j] = dp[i][j] | dp[i-1][j - w[i]];
            if (h[i] <= j)
                dp[i][j] = dp[i][j] | dp[i-1][j - h[i]];
        }
    }
    ROF(i, 0, H+1) {if (dp[N][i]) {cout << i << endl; break;}}
}