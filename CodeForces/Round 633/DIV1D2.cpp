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

vi rScore; 
vi bScore;

int ans = 0;
void dfs(int cur, int par) {
	vi bScoreChildren; bScoreChildren.push_back(0);
	vi rScoreChildren; rScoreChildren.push_back(0);

	int cnt = 0;
	for (int n : graph[cur]) if (n != par) {
		dfs(n, cur);
		++cnt;
		bScoreChildren.push_back(bScore[n]);
		rScoreChildren.push_back(rScore[n]);
	}
	sort(bScoreChildren.rbegin(), bScoreChildren.rend());
	sort(rScoreChildren.rbegin(), rScoreChildren.rend());

	bScore[cur] = cnt ? cnt - 1 + rScoreChildren[0] : 0;
	rScore[cur] = max(bScore[cur], 1 + bScoreChildren[0]);
	ans = max(ans, rScore[cur]);
	if (cnt >= 2) ans = max(ans, max(cnt + (par != -1) - 2 + rScoreChildren[0] + rScoreChildren[1], 1 + bScoreChildren[0] + bScoreChildren[1]));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;

	graph.resize(N);
	rScore.resize(N);
	bScore.resize(N);
	
	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0, -1);
	print(ans);
}