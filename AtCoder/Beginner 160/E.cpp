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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
	vi arra (A);
	F0R(i, A) cin >> arra[i];
	vi arrb (B);
	F0R(i, B) cin >> arrb[i];
	vi arrc (C);
	F0R(i, C) cin >> arrc[i];

	sort(arra.begin(), arra.end());
	sort(arrb.begin(), arrb.end());
	sort(arrc.begin(), arrc.end()); reverse(arrc.begin(), arrc.end());

	int ai = A - X;
	int bi = B - Y;
	ll ASUM = 0;
	ll BSUM = 0;
	FOR(i, ai, A) ASUM += arra[i];
	FOR(i, bi, B) BSUM += arrb[i];
	ll best = ASUM + BSUM;
	ll CSUM = 0;
	F0R(c, C) {
		CSUM += arrc[c];
		if (ai < A && bi < B) {
			if (arra[ai] < arrb[bi]) {
				ASUM -= arra[ai++];
			} else {
				BSUM -= arrb[bi++];
			}
		} else if (ai < A) {
			ASUM -= arra[ai++];
		} else if (bi < B) {
			BSUM -= arrb[bi++];
		} else {
			break;
		}
		best = max(best, ASUM + BSUM + CSUM);
	}
	print(best);

}