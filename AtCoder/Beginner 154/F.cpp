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

ll MOD = 1e9+7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

ll inverse(ll n) {
    return binpow(n, MOD-2);
}


template<class T> struct Seg { 
	const T ID = 0; // comb(ID,b) must equal b
	T combine(T a, T b) { return (a+b) % MOD; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) combine(seg[2*p], seg[2*p+1]);
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

int BIG = 2 * 1e6 + 10;

vll fact (BIG + 1);
ll choose(ll n, ll k) {
	return fact[n] * inverse(n - k) % MOD * inverse(k) % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < BIG; ++i) {
		fact[i] = i * fact[i- 1] % MOD;
	}	

	ll r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	ll ans = 0;
	for (ll c = c1; c <= c2; ++c) {
		ans += choose(r1 - 1 + c, c) * (c2 - c + 1) % MOD * (r2 - r1 + 1) % MOD;
		ans %= MOD;
	}

	for (ll r = r1; r <= r2; ++r) {
		ans += choose(c2 - 1 + r, r) * (r2 - r + 1) % MOD * (c2 - c1 + 1) % MOD;
		ans %= MOD;
	}

	ans += choose(c1 - 1 + r1 - 1, r1 - 1) * (r2 - r1 + 1) % MOD * (c2 - c1 + 1) % MOD;
	ans %= MOD;
	print(ans);
}