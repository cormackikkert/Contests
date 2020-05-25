//AC
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int n,m;
vector<ii> cakes[1<<6];

int main() {
	cin >> n >> m;
	vector<int> masks(n);
	for (int i = 0; i < 6; ++i) {
	  std::string s;
	  std::cin >> s;
	  for (int j = 0; j < s.size(); ++j) if (s[j] == '1') {
	    masks[j] |= (1<<i);
	  }
	}
	for (int i = 0; i < n; ++i) {
		cakes[masks[i]].emplace_back(i+1, i+1);
	}
	std::vector<int> rs(m);
	for (int i = 0; i < 6; ++i) {
	  std::string s;
	  std::cin >> s;
	  for (int j = 0; j < s.size(); ++j) if (s[j] == '1') {
	    rs[j] |= (1<<i);
	  }
	}

	for (int i=0;i<m;i++) {
		int mask = rs[i];

		int other=((1<<6)-1)&(~mask);
		int M=0,Mi=-1,bset;
		for (int extra=other;1;extra=(extra-1)&other) {
			int set=mask|extra;
			if (!cakes[set].empty() && cakes[set].back().first > M) {
				tie(M,Mi) = cakes[set].back();
				bset=set;
			}

			if (extra==0) break;
		}
		if (i) cout << ' ';
		cout << Mi;
		if (Mi!=-1) cakes[bset].pop_back();
	}

	cout << endl;
}
