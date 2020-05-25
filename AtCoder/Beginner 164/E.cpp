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
// vertex, cost
using vertex = pair<ll, ll>;
using edge = tuple<ll, ll, ll>;
vector<vector<edge>> graph;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, M, S; cin >> N >> M >> S;
	S = min(S, 50 * 100LL);
	graph.resize(N);
	F0R(i, M) {
		ll U, V, A, B; cin >> U >> V >> A >> B;
		--U; --V;
		graph[U].push_back(make_tuple(V, A, B));
		graph[V].push_back(make_tuple(U, A, B));
	}
	vll CS(N);
	vll DS(N);
	F0R(i, N) {
		cin >> CS[i];
		cin >> DS[i];
	}
	map<vertex, ll> dist;
	using info = pair<ll, vertex>;
	priority_queue<info, vector<info>, greater<info>> q;
	q.push({0, {0, S}});
	while (!q.empty()) {
		vertex v = q.top().second;
		ll d = q.top().first;
		q.pop();
		if (d != dist[v]) continue;
		// print("SEARCHING", v);
		ll pos = v.first;
		ll sum = v.second;
		// top up
		if (sum + CS[pos] <= 50 * 100) {
			vertex nv = {pos, sum + CS[pos]};
			if ((dist.find(nv) == dist.end()) || (d + DS[pos] < dist[nv])) {
				dist[nv] = d + DS[pos];
				q.push({dist[nv], nv});
			}
		}
		for (edge e : graph[pos]) {
			ll nnv, a, b;
			nnv = get<0>(e);
			a = get<1>(e);
			b = get<2>(e);
			if (sum >= a) {
				vertex nv = {nnv, sum-a};
				if ((dist.find(nv) == dist.end()) || (d + b < dist[nv])) {
					dist[nv] = d + b;
					q.push({dist[nv], nv});
				}
			}
		}
	}

	vll best (N, INF);
	for (pair<vertex, ll> i : dist) {
		best[i.first.first] = min(best[i.first.first], i.second); 
	}

	FOR(i,1, N) print(best[i]);
}