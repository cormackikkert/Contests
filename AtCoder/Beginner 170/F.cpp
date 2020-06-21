#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

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

using state = tuple<int, int, int, int>;

vi DX = {-1, 1, 0, 0};
vi DY = {0, 0, -1, 1};

int main() {
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int H, W, K; cin >> H >> W >> K;
	int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2; --X1; --Y1; --X2; --Y2;
	swap(X1, Y1);
	swap(X2, Y2);

	vector<vector<bool>> grid (H, vector<bool> (W));
	F0R(i, H) {
		F0R(j, W) {
			char c; cin >> c;
			grid[i][j] = c == '@';
		}
	}

	vector<vector<vector<vector<int>>>> dist (H, vector<vector<vector<int>>> (W, vector<vector<int>> (4, vector<int> (K + 1, 1e7))));
	
	deque<state> q;
	F0R(i, 4) {
		q.push_front(make_tuple(X1, Y1, i, K));
		dist[Y1][X1][i][K] = 1;
	}
	
	while (!q.empty()) {
		state v = q.front();
		q.pop_front();

		int x = get<0>(v);
		int y = get<1>(v);
		int d = get<2>(v);
		int r = get<3>(v);
				
		int dis = dist[y][x][d][r];

		F0R(i, 4) {
			if (dis + 1 < dist[y][x][i][K]) {
				dist[y][x][i][K] = dis + 1;
				q.push_back(make_tuple(x, y, i, K));
			}
		}

		if (r > 0) {
			int nx = x + DX[d];
			int ny = y + DY[d];
			if (0 <= nx && nx < W && 0 <= ny && ny < H && !grid[ny][nx]) {
				if (dis < dist[ny][nx][d][r-1]) {
					dist[ny][nx][d][r-1] = dis;
					q.push_front(make_tuple(nx, ny, d, r - 1));
				}
			}
		}
	}
	print("FINISHED");
	int ans = 1e7;
	F0R(i, 4) F0R(k, K+1) ans = min(ans, dist[Y2][X2][i][k]);
	print((ans < 1e7) ? ans : -1)
	; 
}