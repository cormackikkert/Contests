#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int (i) = 0; (i) < (N); ++(i))

template <typename T>
using V = vector<T>;

typedef long double ld;

int main() {
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;
	V<V<int>> umbs(N, V<int>(3));
	for (auto &u : umbs) for (int &e : u) cin >> e;
	umbs.push_back({0, 0, 0});
	umbs.push_back({X, Y, 0});
	set<tuple<ld, ld, int, bool>> Q = {make_tuple(0, K, N, 0)};
	map<tuple<int, ld, bool>, ld> D;
	D[make_tuple(N, K, 0)] = 0;
	while (Q.size()) {
		ld dist, rem;
		int at;
		bool back;
		tie(dist, rem, at, back) = *Q.begin();
		Q.erase(Q.begin());
		auto att = make_tuple(at, rem, back);
		if (dist > D[att])
			continue;
		if (at == N && back == 1) {
			cout << fixed << setprecision(20) << dist << endl;
			return 0;
		}
		REP(i, umbs.size()) {
			ld d = sqrt((umbs[at][0]-umbs[i][0])*(umbs[at][0]-umbs[i][0])+(umbs[at][1]-umbs[i][1])*(umbs[at][1]-umbs[i][1]));
			d -= umbs[at][2]+umbs[i][2];
			d = max(0.0l, d);
			if (d > rem)
				continue;
			auto ct = make_tuple(i, i < N ? K : rem-d, back || i == N+1);
			if (d <= K && (!D.count(ct) || D[ct] > dist+d)) {
				D[ct] = dist+d;
				Q.emplace(dist+d, i < N ? K : rem-d, i, back || i == N+1);
			}
		}
	}
	cout << -1 << endl;
}
