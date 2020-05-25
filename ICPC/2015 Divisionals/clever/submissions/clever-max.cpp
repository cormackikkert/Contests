#include <bits/stdc++.h>

using namespace std;

int N, K;
string names[50], target;

vector<vector<int>> DP;

int f(int bs, int i) {
	if (i == N)
		return 1;
	if (DP[bs][i] != -1)
		return DP[bs][i];
	int cnt = 0;
	for (int j = 0; j < N; ++j) if ((~bs)&(1<<j)) {
		if (find(begin(names[j]), end(names[j]), target[i]) == end(names[j]))
			continue;
		cnt += f(bs|(1<<j), i+1);
	}
	return DP[bs][i] = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (char c : s) if (isupper(c)) {
			names[i].push_back(c);
		}
	}
	for (int i = 0; i < K; ++i) {
		cin >> target;
		if (target.size() != N) {
			cout << 0 << endl;
			continue;
		}
		DP.assign(1<<N, vector<int>(N, -1));
		cout << f(0, 0) << endl;
	}
}
