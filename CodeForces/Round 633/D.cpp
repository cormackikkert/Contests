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

vector<vi> graph;
vi leaf;
vi node;
void dfs(int cur, int par) {
	if (graph[cur].size() == 1) {
		leaf.push_back(cur);
	} else {
		node.push_back(cur);
	}
	
	for (int n : graph[cur]) if (n != par) {
		dfs(n, cur);
	}
}

int bl = 0;
int rl = 0;
void coll(int cur, int col, int par) {
	if (graph[cur].size() == 1) {
		if (col == 0)
			++bl;
		else 
			++rl;
	}

	for (int x : graph[cur]) if (x != par) {
		coll(x, 1-col, cur);
	}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	graph.resize(N);
	print(graph[N]);
	F0R(i, N - 1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0, -1);

	// maximum:
	int hi = 0;
	for (int x : node) {
		bool hasLeaf = false;
		for (int p : graph[x]) {
			if (graph[p].size() == 1) hasLeaf = true;
			else if (p > x) ++hi;
		}
		if (hasLeaf) ++hi;
	}

	// minimum 
	coll(0, 0, -1);
	if (bl == 0 || rl == 0) {
		print(1, hi);
	} else {
		print(3, hi);
	}

}