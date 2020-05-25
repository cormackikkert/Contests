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
vi cols;
vector<vi> graph;
vector<vector<bool>> done;
int currentCol = -1;

void calc(int pos, int rem) {
	if (rem < 0) return;
	if (done[pos][rem]) return;
	done[pos][rem] = true;

	if (rem == 0) cols[pos] = currentCol;

	calc(pos, rem - 1);
	for (int n : graph[pos]) {
		calc(n, rem - 1);
	}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	graph.resize(N);
	cols.resize(N);
	done = vector<vector<bool>> (N, vector<bool> (10));
	F0R(i, M) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int Q; cin >> Q;
	vector<tuple<int, int, int>> queries (Q);
	F0R(i, Q) {
		int v, d, c; cin >> v >> d >> c;
		queries.push_back(make_tuple(v-1, d, c));
	}
	reverse(queries.begin(), queries.end());
	for (tuple<int, int, int> tup : queries) {
		currentCol = get<2>(tup);
		calc(get<0>(tup), get<1>(tup));
	}
	F0R(i, N) print(cols[i]);
}