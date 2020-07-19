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

const int MAXN = 1e3+10;
vll fact (MAXN);
vll invfact (MAXN);
vll inv (MAXN);
vector<vll> precomp (MAXN, vll (MAXN));

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

inline ll inverse(ll n) {
    return binpow(n, MOD-2);
}

inline ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	fact[0] = 1;
    FOR(i, 1, MAXN) fact[i] = fact[i-1] * i % MOD;

    inv[1] = 1;
    FOR(i, 2, MAXN) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

    invfact[0] = 1;
    FOR(i, 1, MAXN) invfact[i] = invfact[i-1] * inv[i] % MOD;

	F0R(i, MAXN) F0R(j, MAXN) {
		precomp[i][j] = inverse(binpow(fact[i], j) * fact[j] % MOD);
	}

	int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	vector<vll> dp (N+1, vll (B+1));
	dp[0][0] = 1; // rem, max i
	F0R(i, N+1) {
		FOR(j, 1, B+1) {
			dp[i][j] += dp[i][j-1];
			if (A <= j && j <= B) {
				for (int x = C; j * x <= i && x <= D; ++x) {
					dp[i][j] += choose(i, j*x) * fact[j*x] % MOD * precomp[j][x] % MOD * dp[i-j*x][j-1];
					dp[i][j] %= MOD;
				}
			}
		}
	}
	print(dp[N][B]);
}