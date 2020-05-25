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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	vll arr (N);
	F0R(i, N) cin >> arr[i];

	ll MAXN = 200000;

	vector<bool> is_prime(MAXN + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= MAXN; i++) {
		if (is_prime[i] && (long long)i * i <= MAXN) {
			for (ll j = i * i; j <= MAXN; j += i)
				is_prime[j] = false;
		}
	}

	vll primes;
	F0R(i, MAXN) if (is_prime[i]) primes.push_back(i);

	map<ll, vll> occ;
	for (ll x : arr) {
		ll n = x;
		for (ll p : primes) {
			ll c = 0;
			if (p * p > n) {
				if (n > 1) occ[n].push_back(1); 
				break;
			}
			while ((n % p) == 0) {
				++c;
				n /= p;
			}
			if (c > 0) {
				occ[p].push_back(c);
			}
		}
	}
	ll gcd = 1;
	for (ll p : primes) {
		if (occ[p].size() >= N - 1) {
			
			int rep;
			if (occ[p].size() == N - 1) {
				// get minimum
				int smo = occ[p][0];
				for (int x : occ[p]) smo = min(smo, x);
				rep = smo;
			} else {
				// get second smallest
				int first = 1e7;
				int second = 1e7;
				for (int x : occ[p]) {
					if (x < first) {
						second = first;
						first = x;
					} else if (x < second) {
						second = x;
					}
				}
				rep = second;
			}

			for (int j = 0; j < rep; ++j) gcd *= p;
		}
	}
	print(gcd);
}