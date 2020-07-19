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

template<class T> struct Seg { 
	const T ID = {1e9, 1e9}; // comb(ID,b) must equal b
	T combine(T a, T b) { return min(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) seg[p] = combine(seg[2*p], seg[2*p+1]);
	}
    
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = combine(ra,seg[l++]);
			if (r&1) rb = combine(seg[--r],rb);
		}
		return combine(ra,rb);
	}
};

struct LCA {
	vector<int> first;
	vector<int> vertex_name, vertex_depth;
	Seg<pii> seg;
	int N;
	LCA(vector<vector<int>>& graph, int root = 0) {
		N = graph.size();
		first.resize(N);
		dfs(graph, root, -1, 0);
		seg.init(vertex_name.size());
		F0R(i, vertex_name.size()) seg.update(i, {vertex_depth[i], vertex_name[i]}); // can be O(N)
	}

	void dfs(vector<vector<int>>& graph, int cur, int par, int depth) {
		first[cur] = vertex_name.size();
		vertex_name.push_back(cur);
		vertex_depth.push_back(depth);
		for (int n : graph[cur]) if (n != par) {
			dfs(graph, n, cur, depth + 1);
			vertex_name.push_back(cur);
			vertex_depth.push_back(depth);
		}
	}
	
	int lca(int v1, int v2) {
		int l = first[v1];
		int r = first[v2];
		if (l > r) swap(l, r);
		return seg.query(l, r).second;
	}
};

vector<vi> graph;
int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M; // num discs, num towers
	
	// stacks
	vi origPlacement (N);
	F0R(i, N) {
		int x; cin >> x; --x;
		origPlacement[i] = x;
	}

	graph.resize(M);
	vi curNode (N);
	vi creationTime (M);
	F0R(i, N) curNode[i] = i;
	
	int newNode = M;

	F0R(i, M-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph.push_back({});
		creationTime.push_back(i+1);
		graph[newNode].push_back(curNode[a]);
		graph[newNode].push_back(curNode[b]);
		graph[curNode[a]].push_back(newNode);
		graph[curNode[b]].push_back(newNode);
		curNode[a] = newNode;
		++newNode;
	}

	LCA lca = LCA(graph, newNode - 1);
	vi adds;
	F0R(i, N-1) {
		adds.push_back(creationTime[lca.lca(origPlacement[i], origPlacement[i+1])]);
	}
	sort(adds.begin(), adds.end());

	int ans = N-1;
	int j = 0;
	F0R(i, M) {
		while (j < N-1 && adds[j] == i) {
			--ans; ++j;
		}
		print(ans);
	}
}