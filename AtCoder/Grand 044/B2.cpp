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

bool graph [500][500][250];
bool cover [500][500];
int cur [500][500];
int N;

vector<pii> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j, int k) {
	graph[i][j][k] = true;
	cur[i][j] = min(cur[i][j], k);
	for (pii d : deltas) {
		int ni = d.first + i;
		int nj = d.second + j;
		int nk = k + cover[i][j];
		if (ni < 0 || ni >= N || nj < 0 || nj >= N || nk >= N || nk >= 250) continue;
		if (graph[ni][nj][nk]) continue;
		if (nk > 0 && graph[ni][nj][nk-1]) continue;
		dfs(ni, nj, nk);
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	F0R(i, 500) F0R(j, 500) {
		cover[i][j] = true;
		F0R(k, 250) graph[i][j][k] = false;
	}

	F0R(i, N) F0R(j, N) {
		cur[i][j] = min(min(i, j), min(N-i-1, N-j-1));
		if (i < 250) graph[i][j][i] = true;
		if (j < 250) graph[i][j][j] = true;
		if (N-i-1 < 250) graph[i][j][N-i-1] = true;
		if (N-j-1 < 250) graph[i][j][N-j-1] = true;
	}

	int ans = 0;
	F0R(t, N*N) {
		int x; cin >> x; --x;
		int i = x/N;
		int j = x%N;
		int best = cur[i][j];
		cover[i][j] = false;
		ans += best;
		dfs(i, j, best);
	}
	print(ans);
}