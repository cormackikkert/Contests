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

int N, M;
vector<vector<pii>> graph; 

vector<bool> seen;
vector<vi> lca_min;
vector<vi> lca_par;
vi depth;

void dfs(int cur, int par, int weight, int d=0) {
	seen[cur] = true;
	depth[cur] = d;

	lca_min[cur][0] = (par == -1) ? 2e9 : weight;
	lca_par[cur][0] = (par == -1) ? cur : par;

	for (int d = 1; d <= 30; ++d) {
		lca_par[cur][d] = lca_par[lca_par[cur][d-1]][d-1];
		lca_min[cur][d] = min(lca_min[cur][d-1], lca_min[lca_par[cur][d-1]][d-1]);
	}

	for (pair<int, int> data : graph[cur]) if (data.first != par) {
		dfs(data.first, cur, data.second, d+1);
	}
}

int max_flow(int a, int b) {
	int min_edge_a = 2e9;
	int min_edge_b = 2e9;

	if (depth[b] > depth[a]) swap(a, b);

	// move a up to the same level as b
	for (int i = 30; i >= 0; --i) if (depth[lca_par[a][i]] >= depth[b]) {
		min_edge_a = min(min_edge_a, lca_min[a][i]);
		a = lca_par[a][i];
	}

	if (a == b) return min(min_edge_a, min_edge_b);

	// find lca
	for (int i = 30; i >= 0; --i) {
		if (lca_par[a][i] != lca_par[b][i]) {
			min_edge_a = min(min_edge_a, lca_min[a][i]);
			min_edge_b = min(min_edge_b, lca_min[b][i]);
			a = lca_par[a][i];
			b = lca_par[b][i];
		}
	}

	min_edge_a = min(min_edge_a, lca_min[a][0]);
	min_edge_b = min(min_edge_b, lca_min[b][0]);

	return min(min_edge_a, min_edge_b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;

	graph.resize(N);
	seen.resize(N);
	depth.resize(N);
	lca_min = vector<vi> (N, vi (31, 2e9));
	lca_par = vector<vi> (N, vi (31));

	F0R(i, M) {
		int a, b, w; cin >> a >> b >> w; --a; --b;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}
	
	for (int i = 0; i < N; ++i) if (!seen[i]) dfs(i, -1, 2e9);
	
	int Q; cin >> Q;
	F0R(i, Q) {
		int a, b; cin >> a >> b; --a; --b;
		print(max_flow(a, b));
	}
}