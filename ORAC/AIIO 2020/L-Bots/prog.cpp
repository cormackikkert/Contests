#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

using vi = vector<int>;

int solve(vi arr) {
	int N = arr.size();

	vector<vi> dp (2, vi (N, 0));

	FOR(i, 1, N) {
		dp[0][i] = max(dp[0][i-1], dp[1][i-1] + arr[i-1] + arr[i]);
		dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
	}
	return max(dp[0][N-1], dp[1][N-1]);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int R, C; cin >> R >> C;
	
	vector<vi> arr1 (R, vi (C));
	vector<vi> arr2 (C, vi (R));
	F0R(i, R) F0R(j, C) {
		int val; cin >> val;
		arr1[i][j] = val;
		arr2[j][i] = val;
	}
	int ans = 0;
	F0R(i, R) ans += solve(arr1[i]);
	F0R(i, C) ans += solve(arr2[i]);
	cout << ans;
}