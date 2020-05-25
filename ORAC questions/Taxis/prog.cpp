#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("taxiin.txt", "r", stdin);
    freopen("taxiout.txt", "w", stdout);

    ll s, n;
    cin >> s >> n;

    int tcost [n];
    int tseat [n];

    for (ll i = 0; i < n; ++i) {
        cin >> tcost[i] >> tseat[i];
    }

    ll dp[s+1];
    dp[0] = 0;

    for (int i = 1; i <= s; ++i) {
        dp[i] = INF;
        for (int t = 0; t < n; ++t) {
            if (!(i - tseat[t] < 0 || dp[i - tseat[t]] == INF))
                dp[i] = min(dp[i], dp[i - tseat[t]] + tcost[t]);

            if (!(i - tseat[t] + 1 < 0 || dp[i - tseat[t] + 1] == INF))
                dp[i] = min(dp[i], dp[i - tseat[t] + 1] + tcost[t]);
        }
    }
    cout << dp[s];
}