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

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K; cin >> N >> K;
	vll arr (N);
	F0R(i, N) cin >> arr[i];
	vll posa;
	vll nega;
	for (ll x : arr) {
		if (x > 0) posa.push_back(x);
		else       nega.push_back(x);
	}
	sort(posa.begin(), posa.end());
	sort(nega.begin(), nega.end());

	ll res = 1;
	if (((posa.size() == 0) && K % 2 == 0) || (posa.size() > 0 && (nega.size() / 2 * 2 + posa.size() >= K))) {
		// create pos
		int i = 0;
		int j = posa.size() - 1;
		while (K >= 2) {
			ll opneg = (i + 1 < nega.size()) ? nega[i] * nega[i+1] : -1;
			ll oppos = (j - 1 >= 0) ? posa[j] * posa[j-1] : -1;
			assert ((opneg != -1) || (oppos != -1));
			if (opneg >= oppos) {
				res *= nega[i] * nega[i+1] % MOD; res %= MOD;
				i += 2;
			} else {
				res *= posa[j] * posa[j-1] % MOD; res %= MOD;
				j -= 2;
			}
			K -= 2;
		}
		if (K == 1) {
			res *= posa[j]; res %= MOD;
		}
	} else {
		// make highest neg
		int i = nega.size() - 1;
		int j = 0;
		while (K) {
			ll opneg = (i >= 0) ? (-nega[i]) : INF;
			ll oppos = (j < posa.size()) ? posa[j] : INF;
			assert ((opneg != INF) || (oppos != INF));
			if (opneg < oppos) {
				res *= (MOD + nega[i]); res %= MOD;
				--i;
			} else {
				res *= posa[j]; res %= MOD;
				j++;
			}
			--K;
		}	
	}
	print((res + MOD) % MOD);
}