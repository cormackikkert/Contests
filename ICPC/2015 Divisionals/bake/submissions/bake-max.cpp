#include <bits/stdc++.h>

using namespace std;

int N, M;

int F[300000];

vector<int> ssd[1<<6];

void read_F() {
	for (int i = 0; i < 6; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j) if (s[j] == '1' ) {
			F[j] |= (1<<i);
		}
	}
}

int main() {
	cin >> N >> M;

	read_F();
	for (int j = 0; j < N; ++j) {
		ssd[F[j]].push_back(j);
	}

	fill(F, F+M, 0);
	read_F();

	for (int i = 0; i < M; ++i) {
		int best_ss = -1;
		for (int ssp = 0; ssp < (1<<6); ++ssp) if ((F[i]&ssp) == F[i] && ssd[ssp].size()) {
			if (best_ss == -1)
				best_ss = ssp;
			else if (ssd[best_ss].back() < ssd[ssp].back())
				best_ss = ssp;
		}
		if (best_ss == -1) {
			cout << -1 << " ";
		} else {
			cout << ssd[best_ss].back()+1 << " ";
			ssd[best_ss].pop_back();
		}
	}
	cout << endl; 
}
