#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

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

map<int, int> degrees; 
map<int, vi> graph;

struct DSU {
    vi p; void init(int n) {p = vi (n, -1);}
    int findSet(int x) { return p[x] < 0 ? x : findSet(p[x]);}
    bool sameSet(int a, int b) { return findSet(a) == findSet(b); }
	int size(int x) { return -p[findSet(x)]; }
	bool joinSet(int x, int y) { // union-by-rank
		x = findSet(x), y = findSet(y); if (x == y) return 0;
		if (p[x] > p[y]) swap(x,y);
		p[x] += p[y]; p[y] = x; return 1;
	}
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	map<int, int> partition;
	map<int, vi> grouping;

	int hi = 0;
	int v1, v2; 
	while (cin >> v1) {
		cin >> v2;
		degrees[v1]++;
		degrees[v2]++;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		hi = max(hi, v1); hi = max(hi, v2);
	}

	DSU dsu; dsu.init(hi + 1);
	vi vertices (hi+1);
	F0R(i, hi+1) vertices[i] = i;
	sort(vertices.begin(), vertices.end(), [](const auto& lhs, const auto& rhs) {
		return -degrees[lhs] < -degrees[rhs];
	});

	vector<bool> skip (hi + 1);
	int maxCol = 0;
	for (int node : vertices) if (!skip[node]) {
		int col = maxCol;
		for (int n : graph[node]) if (partition.find(n) != partition.end()) {
			col = partition[n]; break;
			dsu.joinSet(node, n);
		}
		partition[node] = col;
		grouping[col].push_back(node);

		if (col == maxCol) {
			/*
			for (int n : graph[node]) {
				partition[n] = col;
				grouping[col].push_back(n);
				skip[n] = true;
				break;
			}*/
			++maxCol;
		}
	}

	for (pair<int, vi> data : grouping) {
		for (int x : data.second) cout << x << " ";
		cout << endl;
	}
}