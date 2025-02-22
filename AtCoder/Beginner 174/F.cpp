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

int block_size = 710;
vi arr;

int cur = 0;
int occ [500100] = {0};

inline void add(int val) {
	if (occ[val] == 0) ++cur;
	occ[val]++;
}

inline void remove(int val) {
	if (occ[val] == 1) --cur;
	occ[val]--;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, T; cin >> N >> T;
	arr.resize(N);
	F0R(i, N) cin >> arr[i];
	vector<pair<pii, int>> queries (T);
	F0R(i, T) {
		int l, r; cin >> l >> r; --l; --r;
		queries[i] = {{l, r}, i};
	}

	sort(queries.begin(), queries.end(), [] (const auto& lhs, const auto& rhs) {
		pii q1 = lhs.first;
		pii q2 = rhs.first;
		if ((q1.first / block_size) != (q2.first / block_size)) 
			return (q1.first / block_size) < (q2.first / block_size);
		return q1.second < q2.second;
	});
	
	vi ans (T);

	int curL = 0;
	int curR = 0;
	add(arr[0]);
	for (pair<pii, int> qu : queries) {
		pii q = qu.first;
		
		while (curL < q.first) {
			remove(arr[curL]);
			++curL;
		}
		while (curL > q.first) {
			--curL;
			add(arr[curL]);
		}
		while (curR < q.second) {
			++curR;
			add(arr[curR]);
		}
		while (curR > q.second) {
			remove(arr[curR]);
			--curR;
		}
		ans[qu.second] = cur;
	}
	for (int x : ans) print(x);
}