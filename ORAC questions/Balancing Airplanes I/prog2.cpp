#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("balin.txt", "r", stdin);
    freopen("balout.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> weights (N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    vector<unordered_set<int>> dp (N+1);
    dp[0].insert(0);
    for (int i = 0; i < N; ++i) {
        for (int valid : dp[i]) {
            dp[i+1].insert(valid+weights[i]);
            dp[i+1].insert(valid-weights[i]);
        }
    }
    int best = 60001;
    for (int valid : dp[N]) best = min(best, abs(valid));

    stack<int> p1;
    stack<int> p2;
    for (int i = N; i > 0; --i) {
        if (dp[i-1].find(best-weights[i-1])!=dp[i-1].end())
            p1.push(i), best -= weights[i-1];
        else    
            p2.push(i), best += weights[i-1]; 
    }
    while (!p1.empty()) cout << p1.top() << " ", p1.pop();
    cout << "\n" << ((p2.empty()) ? "0":"");
    while (!p2.empty()) cout << p2.top() << " ", p2.pop();
}