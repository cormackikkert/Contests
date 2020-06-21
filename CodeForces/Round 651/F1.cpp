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

pair<int, int> ask(vi& arr) {
	cout << "? ";
	cout << arr.size() << " ";
	for (int x : arr) cout << x + 1 << " ";
	cout << endl;
	fflush(stdout);
	int node, dist; cin >> node >> dist;
	return {node - 1, dist};
}

int N;
vector<vi> graph;
vi dist;

void dfs(int cur, int par, int d) {
	dist[cur] = d;
	for (int n : graph[cur]) if (n != par) dfs(n, cur, d+1);
}
bool solve() {
	cin >> N;
	graph = vector<vi> (N);
	dist = vi (N);
	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}	
	vi query (N);
	F0R(i, N) query[i] = i;

	pii info = ask(query);

	dfs(info.first, -1, 0);

	int lo = 0;
	int hi = N;

	int p1 = -1;

	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;

		query = vi (0);
		F0R(i, N) if (dist[i] >= mid) query.push_back(i);
		if (query.size() == 0) {
			hi = mid - 1;
		} else {
			pii ret = ask(query);
			p1 = ret.first;

			if (ret.second > info.second) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		
	}

	dist = vi (N);
	dfs(p1, -1, 0);
	
	query = vi (0);
	F0R(i, N) if (dist[i] == info.second) query.push_back(i);

	pii ret = ask(query);
	int p2 = ret.first;

	cout << "! " << p1 + 1 << " " << p2 + 1;
	cout << endl;
	fflush(stdout);
	string ans; cin >> ans;
	if (ans == "Correct") {
		return true;
	} else {
		return false;
	}
}
int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) if (!solve()) break;
}