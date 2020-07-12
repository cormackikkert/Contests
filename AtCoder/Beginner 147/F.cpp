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

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, X, D; cin >> N >> X >> D;
	
	if (D == 0) {
		if (X != 0) print(N+1);
		else print(1);
		return 0;
	}

	if (D < 0) {
		X = X + (N-1) * D; D = abs(D);
	}

	map<int, vector<pll>> seqs;
	F0R(i, N+1) {
		ll lo = X * i + D * i * (i-1)/2;
		ll hi = X * i + D * ((N-1) * N / 2 - (N-i-1) * (N-i)/2);
		seqs[X * i % D].push_back({lo, hi});
	}

	ll ans = 0;
	for (pair<int, vector<pll>> data : seqs) {
		vector<pll> seq = data.second;
		sort(seq.begin(), seq.end());
		ll lval = -1;
		ll hval = -1;
		for (int i = 0; i < seq.size(); ++i) {
			pll range = seq[i];
			if (lval == -1) {
				lval = range.first;
				hval = range.second;
			} else if (range.first <= hval) {
				hval = max(hval, range.second);
			} else {
				ans += (hval - lval) / D + 1;
				lval = range.first;
				hval = range.second;
			}
		}
		ans += (hval - lval) / D + 1;
	}
	print(ans);
}