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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int H, W, N; cin >> H >> W >> N;
	vector<vector<bool>> grid (H, vector<bool> (W));
	vector<vector<bool>> done (H, vector<bool> (W));
	
	vector<pair<int, int>> points; 
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		points.push_back(pair<int, int> {a, b});
		grid[a][b] = true;
	}
	
	vector<vector<int>> cumsum (H + 1, vector<int> (W + 1));
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			cumsum[i][j] = grid[i-1][j-1];
			cumsum[i][j] += cumsum[i-1][j];
			cumsum[i][j] += cumsum[i][j-1];
			cumsum[i][j] -= cumsum[i-1][j-1];
		}
	}

	vector<pii> deltas = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

	vector<int> count (10);

	for (pii point : points) {
		for (pii delta : deltas) {
			int y = point.first + delta.first + 1;
			int x = point.second + delta.second + 1;

			if (y < 2 || x < 2 || x >= W || y >= H) continue;

			if (done[y][x]) continue;
			done[y][x] = true;

			int num = cumsum[y+1][x+1] - cumsum[y-2][x+1] - cumsum[y+1][x-2] + cumsum[y-2][x-2];
			count[num] += 1;
		}
	}
	count[0] = (H - 2) * (W - 2) - count[1] - count[2] - count[3] - count[4] - count[5] - count[6] - count[7] - count[8] - count[9];
	for (int i = 0; i < 10; ++i) {
		print(count[i]);
	}
}