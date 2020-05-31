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

void solve() {
	ll H, C, T; cin >> H >> C >> T;

	if (2 * T <= (H + C)) {
		print(2);
		return;
	}
	if (T >= H) {
		print(1);
		return;
	}


	ll lo = 1; 
	ll hi = 1e8;
	while (lo < hi) {
		ll X = lo + (hi - lo + 1) / 2;
		// temp > T
		if (H * X + C * (X - 1) >= T * (2 * X - 1)) {
			lo = X;
		} else {
			hi = X - 1;
		}	
	}
	
	ll X = lo;

	ll D1 = abs((H * X + C * (X - 1)) - T * (2 * X - 1));
	ll D2 = abs((H * (X + 1) + C * X) - T * (2 * X + 1));

	if (D1 * (2 * X + 1) <= D2 * (2 * X - 1)) {
		print(2 * X - 1);
	} else {
		print(2 * X + 1);
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}