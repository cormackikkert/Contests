#include <bits/stdc++.h>

using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50}, stock(6);

pair<int, vector<int>> pay(int amt) {
	auto rem = stock;
	int cnt = 0;
	for (int i = 5; i >= 0 && amt; --i) while (amt >= coins[i]) {
		amt -= coins[i];
		if (!rem[i]) {
			return {1e9, {}};
		}
		--rem[i];
	}
	return {cnt, rem};
}

int main() {
	for (int &s : stock) {
		cin >> s;
	}
	auto reset = stock;
	int T, ans = 0;
	cin >> T;
	while (T--) {
		int V, tot = 0;
		cin >> V;
		for (int i = 0; i < 6; ++i) {
			int e;
			cin >> e;
			stock[i] += e;
			tot += e*coins[i];
		}

		V = tot-V;

		if (!V) {
			continue;
		}

		for (int v = V; v <= V+100; ++v) {
			auto res = pay(v);
			if (res.first < 1e9) {
				ans += v-V;
				stock = res.second;
				if (v != V) {
					stock = reset;
				}
				break;
			}
		}


	}

	cout << ans << endl;
}
