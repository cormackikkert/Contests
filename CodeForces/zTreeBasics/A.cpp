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

	int N;
	vector<vi> graph;

	void dfs(int cur, int par, vi& dist, int cur_dist = 0) {
		dist[cur] = cur_dist;
		for (int n : graph[cur]) if (n != par) {
			dfs(n, cur, dist, cur_dist+1);
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

		vi dist (N);
		dfs(0, -1, dist);
		int far = max_element(dist.begin(), dist.end()) - dist.begin();
		dfs(far, -1, dist);
		print(3 * (*max_element(dist.begin(), dist.end())));	
	}