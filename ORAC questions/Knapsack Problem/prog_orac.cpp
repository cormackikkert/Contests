#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("knapin.txt", "r", stdin);
    freopen("knapout.txt", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<int> size (N);
    vector<int> cost (N);
    for (int i = 0; i < N; ++i) {
        cin >> size[i] >> cost[i];
    }
    vector<int> dp (M+1);
    for (int s = 0; s <= M; ++s) {
        if (s > 0) dp[s] = dp[s-1];
        for (int i = 0; i < N; ++i) {
            if (s - size[i] < 0) continue;
            dp[s] = max(dp[s], dp[s - size[i]] + cost[i]);
        }
    }
    int cur = M;
    stack<int> res;
    while (cur != 0) {
        for (int i = N-1; i >=0; --i) {
            if (cur - size[i] >= 0 && dp[cur] == dp[cur - size[i]] + cost[i]) {
                res.push(i);
                cur -= size[i]-1;
                break;
            }
        }
        --cur;
    }
    while (!res.empty()) {
        cout << res.top() + 1 << "\n"; res.pop();
    }
}