#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

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

vector<bool> is_prime;
vi primes;
void create_primes(int maxN) {
	is_prime.assign(maxN + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= maxN; ++i) if (is_prime[i]) {
		primes.push_back(i);
		for (int j = i * i; j <= maxN; j += i) 
			is_prime[j] = false;
	}
}

map<int, int> lcmm;

int maxN = 1e6;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vi arr (N);
	F0R(i, N) cin >> arr[i];

	create_primes(maxN);
	for (int x : arr) {
		map<int, int> factorisation;
		
		for (int p : primes) {
			while (x % p == 0) {
				x /= p;
				factorisation[p]++;
			}
		}
		if (x != 1) factorisation[x]++;

		for (pair<int, int> data : factorisation) {
			lcmm[data.first] = max(lcmm[data.first], data.second);
		}
	}

	ll lcm_num = 1;
	for (pair<int, int> data : lcmm) lcm_num = (lcm_num * binpow(data.first, data.second)) % MOD;

	ll total = 0;
	for (int x : arr) {
		map<int, int> factorisation;
		
		for (int p : primes) {
			while (x % p == 0) {
				x /= p;
				factorisation[p]++;
			}
		}
		if (x != 0) factorisation[x]++;

		ll res = lcm_num;
		for (pair<int, int> data : factorisation) {
			res *= inverse(binpow(data.first, data.second));
			res %= MOD;
		}
		total += res;
		total %= MOD;
	}
	print(total);
}
