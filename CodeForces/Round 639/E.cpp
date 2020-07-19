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
vector<vi> graph;
vector<vi> graphr;

vector<int> colouring;
vector<bool> visited;

bool hasCycle = false;
void checkCycle(int cur) {
	colouring[cur] = 1;
	for (int n : graph[cur]) {
		hasCycle |= colouring[n] == 1;
		if (colouring[n] == 0) checkCycle(n);
	}
	colouring[cur] = 2;
}

vi ordering;

void dfs(int cur) {
	visited[cur] = true;
	for (int n : graph[cur]) {
		if (!visited[n]) dfs(n);
	}
	ordering.push_back(cur);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	graph.resize(N);
	graphr.resize(N);
	F0R(i, M) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graphr[b].push_back(a);
	}

	// cycle => impossible	
	colouring.resize(N);
	F0R(i, N) if (colouring[i] == 0) checkCycle(i);
	if (hasCycle) {
		print(-1);
		return 0;
	}


	visited.resize(N);
	F0R(i, N) if (!visited[i]) dfs(i);
	
	vi compares (N);
	vi comparesR(N);
	F0R(i, N) {
		compares[i] = i;
		comparesR[i] = i;
	}

	for (int node : ordering) {
		for (int n : graph[node]) compares[node] = min(compares[node], compares[n]);
	}

	reverse(ordering.begin(), ordering.end());

	for (int node : ordering) {
		for (int n : graphr[node]) comparesR[node] = min(comparesR[node], comparesR[n]);
	}
	
	int ans = 0;
	F0R(i, N) ans += min(compares[i], comparesR[i]) == i;
	print(ans);

	F0R(i, N) {
		cout << ((min(compares[i], comparesR[i]) == i) ? 'A' : 'E');
	}
	cout << endl;
}
