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

template<class T> struct Seg { 
	const T ID = 0; // comb(ID,b) must equal b
	T combine(T a, T b) { return a+b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) seg[p] = combine(seg[2*p], seg[2*p+1]);
	}
    
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = combine(ra,seg[l++]);
			if (r&1) rb = combine(seg[--r],rb);
		}
		return combine(ra,rb);
	}
};

void solve() {
	ll N, M; cin >> N >> M;
	vector<pair<ll, ll>> arr (M);
	F0R(i, M) {
		int a, b; cin >> a >> b;
		arr[i] = {a, b};
	}
	sort(arr.rbegin(), arr.rend());

	vll begins (M);
	F0R(i, M) begins[i] = arr[i].first;

	Seg<ll> seg; seg.init(M);
	F0R(i, M) seg.update(i, begins[i]);

	ll ans = 0;
	F0R(i, M) {
		pair<ll, ll> data = arr[i];

		ll a = data.first;
		ll b = data.second;

		ll lo = 0;
		ll hi = M-1;
		while (lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2;
			if (begins[mid] > b) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}

		if (begins[0] <= b) {
			ans = max(ans, a + b * (N - 1));
		} else if (lo + 1 >= N) {
			ans = max(ans, seg.query(0, N-1));
		} else {
			if (i > lo) {
				ans = max(ans, seg.query(0, lo) + a + b * (max(0LL, N - lo - 2)));
			} else {
				ans = max(ans, seg.query(0, lo) + b * (N - lo - 1));
			}
		}
		
	}
	print(ans);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}