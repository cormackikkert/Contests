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

ll gcd(ll a, ll b) {
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}
bool solveSmart(ll A, ll B, ll C, ll D) {
	ll d = D % B;

	ll hi = 0;

	
	if (D < B) {
		hi = C + 1; // NO
	} else if (B > A) {
		hi = C + 1; // NO
	} else if (d == 0) { // now actual cases
		hi = A % B;
	} else {
		d = gcd(B, d);
		hi = B + (A % d - d);
	}

	if (hi <= C) {
		return true;
	} else {
		return false;
	}
}

bool solveDumb(ll A, ll B, ll C, ll D) {
	for (int i = 0; i < 1000; ++i) {
		A -= B;
		if (A < 0) return false;
		if (A <= C) A += D;
	}
	return true;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) {
		ll A, B, C, D; cin >> A >> B >> C >> D;
		print(solveSmart(A, B, C, D) ? "Yes" : "No");
	}
}