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

int N, K;
vector<vi> graph;
vi label;

vi isW (2);
vi isB (2);

void dfs1(int cur, int par, int col) {
	if (label[cur] >= 0) {
		if (col) isW[label[cur] % 2] = true;
		else     isB[label[cur] % 2] = true;
	}
	for (int n : graph[cur]) if (n != par) {
		dfs1(n, cur, 1-col);
	}
}

bool fail = false;
vi lo;
vi hi;
void dfs2(int cur, int par, bool isEven) {
	if (graph[cur].size() - (par != -1) == 0) {
		// leaf
		if (label[cur] == -1) {
			lo[cur] = -1e6 - !isEven;
			hi[cur] = 1e6 + !isEven;
		} else {
			lo[cur] = label[cur];
			hi[cur] = label[cur];
		}
	} else {
		int clo = -1e7;
		int chi = 1e7;
		for (int n : graph[cur]) if (n != par) {
			dfs2(n, cur, !isEven);
			clo = max(clo, lo[n]-1);
			chi = min(chi, hi[n]+1);
		}
		if (clo > chi) fail = true;
		lo[cur] = clo;
		hi[cur] = chi;
		if (label[cur] != -1) {
			if (!(lo[cur] <= label[cur] && label[cur] <= hi[cur])) fail = true;
			lo[cur] = label[cur];
			hi[cur] = label[cur];
		}
	}
}

void dfs3(int cur, int par, int val) {
	if (val - 1 >= lo[cur]) {
		label[cur] = val - 1;
	} else {
		label[cur] = val + 1;
	}
	for (int n : graph[cur]) if (n != par) {
		dfs3(n, cur, label[cur]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	graph.resize(N);
	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	label = vi (N, -1);
	cin >> K;
	F0R(i, K) {
		int v, l; cin >> v >> l; --v;
		label[v] = l;
	}

	// T/F -> B/W
	dfs1(0, -1, 0);
	if ((isW[0] && isW[1]) || (isB[0] && isB[1])) {
		print("No"); return 0;
	}

	if (isW[0]) isB[1] = true;
	if (isB[1]) isW[0] = true;
	if (isW[1]) isB[0] = true;
	if (isB[0]) isW[1] = true;

	lo.resize(N); hi.resize(N);
	dfs2(0, -1, isB[0]);
	if (fail) {
		print("No"); return 0;
	}

	dfs3(0, -1, lo[0]+1);
	print("Yes");
	F0R(i, N) print(label[i]);
}