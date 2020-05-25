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
using pii = pair<int, int>;

int N, M;
vector<vector<pii>> ngraph;
vector<vector<pii>> rgraph;


vll dijkstra(vector<vector<pii>> g) {
	vll distance (N, INF); 
	distance[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, 0});
	while (!q.empty()) {
		int v = q.top().second;
		int d = q.top().first;
		
		q.pop();

		if (d != distance[v]) continue;

		for (pii edge : g[v]) {
			int to = edge.first;
			int len = edge.second;
			if (d + len < distance[to]) {
				distance[to] = d + len;
				q.push(pii {distance[to], to});
			}
		}
	}
	return distance;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	ngraph.resize(N);
	rgraph.resize(N);
	
	F0R(i, M) {
		int a, b, c; cin >> a >> b >> c; --a; --b;
		ngraph[a].push_back(pii {b, c});
		rgraph[b].push_back(pii {a, c});
	}

	vll d1 = dijkstra(ngraph);
	vll d2 = dijkstra(rgraph);

	for (int i = 1; i < N; ++i) {
		if (d1[i] == INF || d2[i] == INF) {
			print(-1);
		} else {
			print(d1[i] + d2[i]);
		}
	}
}