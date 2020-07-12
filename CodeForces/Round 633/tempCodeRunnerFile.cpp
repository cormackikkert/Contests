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
vi dp;
vi cs; // child score

void dfs(int cur, int par) {
	int children = graph[cur].size() - 1 + (par == -1);

	if (children == 0)  {
		dp[cur] = 1; return;
	}

	int hidp = 1;
	int hics = 0;
	for (int n : graph[cur]) if (n != par) {
		dfs(n, cur);
		hidp = max(hidp, dp[n]);
		hics = max(hics, cs[n]);
	}
	cs[cur] = hidp;
	dp[cur] = max(1 + hics, children - 1 + hidp);	
}

int best = 0;
void dfs2(int cur, int par, int pardp, int parcs) {
	int children = graph[cur].size() - 1 + (par == -1);
	multiset<int> dps; dps.insert(pardp); dps.insert(1);
	multiset<int> css; css.insert(parcs);

	// recalculate current hidp/hics
	int hidp = pardp; hidp = max(hidp, 1);
	int hics = parcs;
	for (int n : graph[cur]) if (n != par) {
		hidp = max(hidp, dp[n]);
		hics = max(hics, cs[n]);

		dps.insert(dp[n]);
		css.insert(cs[n]);
	}
	
	// print("PAR:", par, pardp, parcs);
	print("REE: ", cur, max(1 + hics, children - 1 + hidp));
	best = max(best, max(1 + hics, children - 1 + hidp));

	for (int n : graph[cur]) if (n != par) {
		dps.erase(dps.find(dp[n]));
		int new_hidp = *dps.rbegin();
		css.erase(css.find(cs[n]));
		int new_hics = *css.rbegin();

		int ncs = new_hidp;
		int ndp = max(1 + new_hics, children - 1 + new_hidp);

		dfs2(n, cur, ndp, ncs);

		dps.insert(dp[n]);
		css.insert(cs[n]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	
	dp.resize(N);
	cs.resize(N);
	graph.resize(N);

	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a); 
	}
	F0R(i, N) {
		dp = vi (N, 0);
		cs = vi (N, 0);
		dfs(i, -1);
		print("ACTUAL", i, dp[i]);
	}
	dp = vi (N, 0);
	cs = vi (N, 0);
	dfs(0, -1);
	print("REEE", dp, cs);
	dfs2(0, -1, 0, 0);
}