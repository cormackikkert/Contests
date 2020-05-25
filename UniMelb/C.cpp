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


template<class T> struct Seg { 
	const T ID = 0; // comb(ID,b) must equal b
	T combine(T a, T b) { return max(a, b); } 
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

Seg<ll> population;

vll pop_city;

struct DSU {
    vi p; void init(int n) {p = vi (n, -1);}
    int findSet(int x) { return p[x] < 0 ? x : findSet(p[x]);}
    bool sameSet(int a, int b) { return findSet(a) == findSet(b); }
	int size(int x) { return -p[findSet(x)]; }
	bool joinSet(int x, int y) { // union-by-rank
		x = findSet(x), y = findSet(y); if (x == y) return 0;
		if (p[x] > p[y]) swap(x,y);
		p[x] += p[y]; p[y] = x;
		population.update(x, population.query(x, x) + population.query(y,y)); return 1;
	}
};

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M, Q; //cin >> N >> M >> Q;
	N = 100000;
	M = 100000;
	Q = 100000;
	population.init(N);
	pop_city.resize(N);

	DSU dsu; dsu.init(N);

	F0R(i, N) pop_city[i] = rand(); // >> pop_city[i];
	F0R(i, N) population.update(i, pop_city[i]);
	vector<pii> edges (M);
	set<pii> activeEdges;
	F0R(i, M) {
		int a, b; a = rand() % N; b = rand() % N; //cin >> a >> b; --a; --b;
		edges[i] = {a, b};
		activeEdges.insert(edges[i]);
	}


	vector<pair<int, int>> queries (Q);

	F0R(i, Q) {
		// char c; cin >> c;
		int r = rand();
		if (r & 1) {
			int K; // cin >> K; --K;
			K = rand() % M;
			// print(1, K);
			int v1 = edges[K].first;
			int v2 = edges[K].second;

			if (activeEdges.find(edges[K]) != activeEdges.end())
				activeEdges.erase(activeEdges.find(edges[K]));
			queries[i] = {-1, K};
		} else {
			// print(2);
			int A, K; // cin >> A >> K;
			A = rand() % N + 1;
			K = rand() % M;
			// print(A, K);
			queries[i] = {A-1, pop_city[A-1]};
			pop_city[A-1] = K;
			// print("here");
			population.update(A-1, K);
		}
	}
	print("COMPLETE");

	for (pii edge : activeEdges) {
		int p1 = dsu.findSet(edge.first);
		int p2 = dsu.findSet(edge.second);

		if (p1 != p2) {
			dsu.joinSet(p1, p2);
		}
	}

	reverse(queries.begin(), queries.end());
	
	vll answers (Q);
	answers[Q-1] = population.query(0, N-1);
	F0R(i,Q-1) {
		if (queries[i].first == -1) {
			// open road
			int v1 = edges[queries[i].second].first;
			int v2 = edges[queries[i].second].second;
			dsu.joinSet(v1, v2);
			
		} else {
			// change population
			int p = dsu.findSet(queries[i].first);
			population.update(p, population.query(p, p) +  queries[i].second - pop_city[queries[i].first]);
			pop_city[queries[i].first] = queries[i].second;
		}
		answers[Q-i-2] = population.query(0, N-1);
	}
	F0R(i, Q) print(answers[i]);
}