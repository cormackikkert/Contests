#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	vector<vector<int>> lights(N, vector<int>(4));
	for (auto &v : lights) for (int &e : v) cin >> e;
	for (auto &l : lights) {
		int len = l[2]+l[3], t = l[0]-l[1], rem = t%len;
		if (rem > l[2] || t < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
