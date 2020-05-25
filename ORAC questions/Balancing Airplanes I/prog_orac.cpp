#include <bits/stdc++.h>
using namespace std;

int conv(int i) {return (i >= 0) ? i : 120005+i;}
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

    vector<vector<bool>> dp (N+1, vector<bool>(120005));
    dp[0][0] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = -60000; j <= 60000; ++j) {
            if (!dp[i][conv(j)]) continue;
            if (j+weights[i] <= 60000) dp[i+1][conv(j+weights[i])] = true;
            if (j-weights[i] >=-60000) dp[i+1][conv(j-weights[i])] = true;
        }
    }

    int best = 0;
    for (; best <= 60000; ++best) if (dp[N][best]) break;

    stack<int> p1;
    stack<int> p2;
    for (int i = N; i > 0; --i) {
        if (dp[i-1][conv(best-weights[i-1])])
            p1.push(i), best -= weights[i-1];
        else    
            p2.push(i), best += weights[i-1]; 
    }

    while (!p1.empty()) cout << p1.top() << " ", p1.pop();
    cout << "\n" << ((p2.empty()) ? "0":"");
    while (!p2.empty()) cout << p2.top() << " ", p2.pop();
}