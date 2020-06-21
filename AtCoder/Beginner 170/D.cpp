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

const int MAXA = 1e6+10;
vector<bool> is_prime (MAXA, true);
vi primes;

vi factorize(int x) {
	vi facts;
	for (int p : primes) {
		if (p * p > x) break;
		if (x % p == 0) facts.push_back(p);
		while (x % p == 0) x /= p;
	}
	if (x > 1) facts.push_back(x);	
	return facts;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vi arr (N);
	F0R(i, N) cin >> arr[i];
	
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAXA; ++i) {
		if (is_prime[i]) primes.push_back(i);

		if (is_prime[i] && 1LL * i * i <= MAXA)  {
			for (int j = i * i; j <= MAXA; j += i) {
				is_prime[j] = false;
			}
		}
	}

	map<int, int> occ;
	for (int x : arr) {
		vi facts = factorize(x);
		for (int p : facts) occ[p]++;
	}
	print(occ);
	int ans = 0;
	for (int x : arr) {
		vi facts = factorize(x);
		bool diff = false;
		for (int p : facts) if (occ[p] != 1) diff = true;
		ans += !diff;
	}
	print(ans);
	
}