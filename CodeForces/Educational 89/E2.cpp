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
 
ll MOD = 998244353;
template<class T> struct Seg { 
	const T ID = INF; // comb(ID,b) must equal b
	T combine(T a, T b) { return min(a, b); } 
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
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vi AS (N);
	vi BS (M);
	F0R(i, N) cin >> AS[i];
	F0R(i, M) cin >> BS[i];
 
	Seg<ll> seg; seg.init(N);
	F0R(i, N) seg.update(i, AS[i]);
 
	vi inds (M, -1);
	vi smol (M, -1);
 
	int p = M - 1;
	int p2 = M - 1;
	R0F(i, N) {
		while (p2 >= 0 && AS[i] < BS[p2]) {
			smol[p2] = i;
			--p2;
		}
		if (p >= 0 && AS[i] == BS[p]) {
			inds[p] = i;
			--p;
		}
	}
	ll ans = 1;
	ROF(i, 1, M) {
		if (smol[i] > inds[i] || seg.query(inds[i], N-1) < BS[i]) {
			ans = 0; break;
		}
		ans *= (inds[i] - smol[i]) % MOD;
	}
	if ((p2 == -1) || (p != -1)) ans = 0;
	print(ans);
}