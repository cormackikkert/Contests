#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;
ll MOD = 1e9+7;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void print() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void print(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); print(ts...); 
	}
}

using namespace output;

using pos = tuple<int, int, int, int>;
int dist[101][101][4][51];
ll ways[101][101][4][51];
vector<pair<int, int>> deltas = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int M; cin >> M;
	int SX, SY; cin >> SX >> SY;
	int TX, TY; cin >> TX >> TY;

	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			for (int d = 0; d <4; ++d) {
				for (int r = 0; r <= M; ++r) {
					dist[i][j][d][r] = (int) 1e9;
					ways[i][j][d][r] = 0LL;
				}
			}
		}
	}
	
	queue<pos> q;

	for (int del = 0; del < 4; ++del) {
		dist[SY][SX][del][M] = 0;
		ways[SY][SX][del][M] = 1;
		q.push(make_tuple(SX, SY, del, M));
	}
	
	while (!q.empty()) {
		pos p = q.front(); q.pop();
		int x = get<0>(p);
		int y = get<1>(p);
		int d = get<2>(p);
		int r = get<3>(p);
		// print(x, y, d, dist[y][x][d][r]);
		// print("DOING", x, y, dist[y][x][d][r]);//, ways[y][x][d][r]);
		for (int del = 0; del < 4; ++del) {
			if (r == 1 && del == d) continue;

			int nx = x + deltas[d].first;
			int ny = y + deltas[d].second;
			if (nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
			
			if (dist[y][x][d][r] + 1 < dist[ny][nx][del][M]) {
				ways[ny][nx][del][M] = ways[y][x][d][r];
				dist[ny][nx][del][M] = dist[y][x][d][r] + 1;
				q.push(make_tuple(nx, ny, del, M));
			} else if (dist[y][x][d][r] + 1 == dist[ny][nx][del][M]) {
				ways[ny][nx][del][M] += ways[y][x][d][r];
				ways[ny][nx][del][M] %= MOD;
			}
		}
	}
	int minDist = dist[TY][TX][0][0];
	for (int d = 0; d < 4; ++d) for (int m = 0; m <= M; ++m) {
		minDist = min(minDist, dist[TY][TX][d][m]);
	}
	ll w = 0;
	for (int d = 0; d < 4; ++d) for (int m = 0; m <= M; ++m) {
		if (dist[TY][TX][d][m] == minDist) {
			// print(TY, TX, d, m, ways[TY][TX][d][m]);
			w += ways[TY][TX][d][m];
			w %= MOD;
		}
	}
	print(minDist, w);
}