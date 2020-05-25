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
using pll = pair<ll, ll>;

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

vll primes;
map<ll, ll> getFact(ll num) {
	map<ll, ll> fact;
	for (ll p : primes) {
		if (p * p > num) break;
		while (num % p == 0) {
			fact[p]++;
			num /= p;
		}
	}
	if (num > 1) fact[num]++;
	return fact;
}
void solve() {
	int N, M; cin >> N >> M;
	
	vi graph (2 * N);

	vll value (N);
	F0R(i, N) cin >> value[i];
	
	vll subset (N);
	F0R(i, M) {
		int a, b; cin >> a >> b; --a; --b;
		subset[a] += value[b];
	}

	print(subset);

	int BIG = 1e6+10;
	vector<bool> isPrime (BIG+4, true);
	isPrime[0] = false;
	isPrime[1] = false;
	FOR(i, 2, BIG+1) if (isPrime[i]) {
		for (ll j = 1LL * i * i; j <= BIG; j += i) isPrime[j] = false;
	}


	F0R(i, BIG+1) if (isPrime[i]) primes.push_back(i);
	map<ll, ll> gcd = getFact(subset[0]);
	
	FOR(i, 1, N) {
		map<ll, ll> f2 = getFact(subset[i]);
		for (pll x : gcd) {
			gcd[x.first] = min(x.second, f2[x.first]);
		}
	}

	ll ans = 0;
	for (pll x : gcd) ans += x.first * x.second;
	print(ans);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	F0R(i, T) solve();
}