#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

vector<pii> deltas = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int X, Y; cin >> X >> Y; --X; --Y;
	bool seen [36][36][36][36];
	short dist [36][36][36][36];

	queue<pair<pii, pii>> q;
	q.push({{0, 0}, {X, Y}});
	while (!q.empty()) {
		pair<pii, pii> val = q.front(); q.pop();
		pii u = val.f;
		pii o = val.s;
		if (u == pii {N-1, N-1}) {
			cout << dist[u.f][u.s][o.f][o.s] << endl;
			return 0;
		}
		for (pii d : deltas) {
			pii no = {o.f + d.f, o.s + d.s};
			
			// u, no
			if (0 <= no.f && no.f < N) {
				if (no != u) {
					if (!seen[u.f][u.s][no.f][no.s]) {
						q.push({u, no});
						dist[u.f][u.s][no.f][no.s] = dist[u.f][u.s][o.f][o.s] + 1;
						seen[u.f][u.s][no.f][no.s] = true;
					}
				} else {
					if (!seen[o.f][o.s][u.f][u.s]) {
						q.push({o, u});
						dist[o.f][o.s][u.f][u.s] = dist[u.f][u.s][o.f][o.s] + 1;
						seen[o.f][o.s][u.f][u.s] = true;
					}
				}
			}
		}
	}

}