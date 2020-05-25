#include <bits/stdc++.h>

using namespace std;

int main() {
	map<char, char> beats = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
	map<char, char> morphs = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};
	int n, k, l, m;
	string sa, sb;
	cin >> n >> k >> l >> m >> sa >> sb;
	int res = -1e9;
	for (int i = 0; i < n-k+1; ++i) {
		int worst_alice = 1e9;
		for (int j = 0; j < n-k+1; ++j) {
			string b = sb.substr(j, k);
			int worst_bob = 1e9;
			for (int ii = 0; ii < k-l+1; ++ii) {
				string a = sa.substr(i, k);
				for (int jj = ii; jj < ii+l; ++jj) {
					a[jj] = morphs[a[jj]];
				}
				int aw = 0, bw = 0, winner = 0;
				for (int jj = 0; jj < k; ++jj) {
					aw += beats[a[jj]] == b[jj];
					bw += beats[b[jj]] == a[jj];
					if (bw == m) {
						winner = 1;
						break;
					} else if (aw == m) {
						winner = -1;
						break;
					}
				}
				worst_bob = min(worst_bob, winner);
			}
			worst_alice = min(worst_alice, worst_bob*-1);
		}
		res = max(res, worst_alice);
	}
	if (!res) {
		cout << "Draw" << endl;
	} else {
		cout << (res == -1 ? "Bob" : "Alice") << endl;
	}
}
