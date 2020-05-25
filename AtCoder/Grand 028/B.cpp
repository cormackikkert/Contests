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

ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	vll arr (N);
	F0R(i, N) cin >> arr[i];

	vll mults (N);
	mults[0] = 1; mults[1] = 1;
	FOR(i, 2, N) mults[i] = (2 * mults[i-1]) % MOD;

	vll sums (N);
	ll total = 0;
	F0R(i, N) {
		total += arr[i];
		sums[i] = (total * mults[N-i-1]) % MOD;
	}

	ll S = 0;
	F0R(i, N) S = (S + sums[i]) % MOD;

	ll E = 0;
	F0R(i, N) E = (E + sums[i] * (i + 1)) % MOD;

	ll hi = N;

	ll ans = 0;
	F0R(i, N) {
		ll lhs = mults[i];
		print(E);
		ans += lhs * E;
		ans %= MOD;

		ll count = 0;
		F0R(j, N - i) count += mults[j];
		S -= arr[i] * count;
		S += MOD * MOD; S %= MOD;

		E -= hi * (hi + 1) / 2;
		E += MOD * MOD; E %= MOD;

		print("REMOVING", S);
		E -= S;
	}
	print(ans);
}