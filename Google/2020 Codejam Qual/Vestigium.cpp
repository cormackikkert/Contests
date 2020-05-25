#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<vector<int>> arr (N, vector<int> (N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	int a1, a2, a3;
	cout << a1 << " " << a2 << " " << a3;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
}