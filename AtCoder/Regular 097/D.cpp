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
vi perm;

vi found_inds;
vi found_pers; 
vi temp;
vector<bool> visited;

void dfs(int pos) {
	found_inds.push_back(pos);
	found_pers.push_back(perm[pos]);
	visited[pos] = true;

	for (int n : graph[pos]) {
		if (visited[n]) continue;
		dfs(n);
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;

	perm.resize(N); 
	graph.resize(N);
	visited.resize(N);
	temp.resize(N);

	for (int i = 0; i < N; ++i) {cin >> perm[i]; --perm[i];}

	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		if (visited[i]) continue;

		found_inds.clear();
		found_pers.clear();
		temp.clear(); 
		
		dfs(i);

		temp.resize(found_inds.size() + found_pers.size());
		
		sort(found_inds.begin(), found_inds.end());
		sort(found_pers.begin(), found_pers.end());

		auto it = set_intersection(found_inds.begin(), found_inds.end(), found_pers.begin(), found_pers.end(), temp.begin());
		ans += it - temp.begin();
	}
	print(ans);
}