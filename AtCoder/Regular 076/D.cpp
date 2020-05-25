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

struct DSU {
    vi p; void init(int n) {p = vi (n, -1);}
    int findSet(int x) { return p[x] < 0 ? x : findSet(p[x]);}
    bool sameSet(int a, int b) { return findSet(a) == findSet(b); }
	int size(int x) { return -p[findSet(x)]; }
	bool joinSet(int x, int y) { // union-by-rank
		x = findSet(x), y = findSet(y); if (x == y) return 0;
		if (p[x] > p[y]) swap(x,y);
		p[x] += p[y]; p[y] = x; return 1;
	}
};

using city = pair<int, pii>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N; cin >> N;
	
	vi xs (N);
	vi ys (N);
	vector<city> cxs (N);
	vector<city> cys (N);

	F0R(i, N) {
		cin >> xs[i] >> ys[i];
		cxs[i] = {i, pii {xs[i], ys[i]}};
		cys[i] = {i, pii {xs[i], ys[i]}};
	}

	sort(cxs.begin(), cxs.end(), [] (const city& lhs, const city& rhs) {
		return lhs.second.first < rhs.second.first;
	});

	sort(cys.begin(), cys.end(), [] (const city& lhs, const city& rhs) {
		return lhs.second.second < rhs.second.second;
	});

	priority_queue<city, vector<city>, greater<city>> q;

	FOR(i, 1, N) {
		city c1, c2;

		c1 = cxs[i-1];
		c2 = cxs[i];

		q.push({c2.second.first - c1.second.first, {c1.first, c2.first}});

		c1 = cys[i-1];
		c2 = cys[i];

		q.push({c2.second.second - c1.second.second, {c1.first, c2.first}});
	}

	ll ans = 0;

	DSU dsu; dsu.init(N);
	while (!q.empty()) {
		city res = q.top(); q.pop();
		if (dsu.sameSet(res.second.first, res.second.second)) continue;

		ans += res.first;
		dsu.joinSet(res.second.first, res.second.second);
	}
	print(ans);
}