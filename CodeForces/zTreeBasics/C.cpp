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

int N;
vector<vi> graph;
vector<vi> lift;
vi depth;

void dfs(int cur, int par, int d=0) {
	depth[cur] = d;
	lift[cur][0] = (par == -1) ? cur : par;
	for (int n : graph[cur]) if (n != par) dfs(n, cur, d+1);
}

int move_up(int a, int k) {
	for (int i = 0; i <= 30; ++i) if (k & (1 << i)) {
		a = lift[a][i];
	}
	return a;
}

int lca(int a, int b) {
	if (depth[b] > depth[a]) swap(a, b);
	a = move_up(a, depth[a]-depth[b]);
	if (a == b) return a;

	for (int i = 30; i >= 0; --i) {
		if (lift[a][i] != lift[b][i]) {
			a = lift[a][i];
			b = lift[b][i];
		}
	}
	return lift[a][0];
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;

	graph.resize(N);
	depth.resize(N);

	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	lift = vector<vi> (N, vi (31));

	dfs(0, -1);
	// binary lift
	
	for (int i = 1; i <= 30; ++i) {
		for (int n = 0; n < N; ++n) {
			lift[n][i] = lift[lift[n][i-1]][i-1];
		}
	}

	int Q; cin >> Q;
	F0R(i, Q) {
		int a, b, c; cin >> a >> b >> c; --a; --b;
		int l = lca(a, b);
		
		c = min(c, depth[a] + depth[b] - 2 * depth[l]);
		if (depth[a] - depth[l] >= c) {
			print(move_up(a, c) + 1);
		} else {
			print(move_up(b, (depth[b] - depth[l]) - (c - (depth[a] - depth[l]))) + 1);
		}
	}
}