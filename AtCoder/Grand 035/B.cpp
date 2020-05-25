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
		pr("{",x.first,", ",x.second,"}"); 
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
vector<pii> edges;
vector<vi> graph;
set<pii> used;
vector<pii> finalEdges;
vi goingOut;
bool fail = false;

vector<bool> seen;

void dfs(int cur) {
	seen[cur] = true;
	for (int n : graph[cur]) if (!seen[n]) {
		used.insert(pii {min(cur, n), max(cur, n)});
		dfs(n);
	}
}

void calc(int cur, int par) {
	seen[cur] = true;
	for (int n : graph[cur]) if (!seen[n]) {
		calc(n, cur);
	}

	if (goingOut[cur] % 2 == 0) {
		if (par != -1) {
			finalEdges.push_back({par, cur});
			goingOut[par]++;
		}
	} else {
		if (par != -1) {
			finalEdges.push_back({cur, par});
			goingOut[cur]++;
		} else fail = true;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	
	graph.resize(N);
	edges.resize(M);
	goingOut.resize(N);

	F0R(i, M) {
		int a, b; cin >> a >> b; --a; --b;
		edges[i] = {a, b};
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	seen = vector<bool> (N);
	dfs(0);

	for (pii e : edges) {
		pii ie = {min(e.first, e.second), max(e.first, e.second)};
		if (used.find(ie) == used.end()) {
			finalEdges.push_back(ie);
			goingOut[ie.first]++;
		}
	}
	seen = vector<bool> (N);
	calc(0, -1);

	if (fail) {
		print(-1);
	} else {
		for (pii e : finalEdges) {
			print(e.first + 1, e.second + 1);
		}
	}
}