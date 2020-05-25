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

vector<vector<char>> col;
vector<vector<char>> dir;
vector<vector<int>> dist;
vector<vector<bool>> done;

int cycleLength = 0;
void dfs(int x, int y, int d) {
	if (dist[y][x] != -1) {
		if (dist[y][x] == -2) return;
		
		cycleLength = d - dist[y][x];
		return;
	}

	dist[y][x] = d;

	if (dir[y][x] == 'R') {
		dfs(x+1, y, d + 1);
	} else if (dir[y][x] == 'L') {
		dfs(x-1, y, d + 1);
	} else if (dir[y][x] == 'U') {
		dfs(x, y-1, d + 1);
	} else {
		dfs(x, y+1, d + 1);
	}
}
void solve() {
	int N, M; cin >> N >> M;
	col = vector<vector<char>> (N, vector<char> (M));
	dir = vector<vector<char>> (N, vector<char> (M));
	dist = vector<vector<int>> (N, vector<int> (M, -1));
	done = vector<vector<bool>> (N, vector<bool> (M));
	F0R(i, N) F0R(j, M) cin >> col[i][j];
	F0R(i, N) F0R(j, M) cin >> dir[i][j];
	
	int hi = 0;
	F0R(i, N) F0R(j, N) if (dist[i][j] == -1) {
		cycleLength = 0;
		dfs(i, j, 0);
		hi += cycleLength;
	}
	print(hi);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}