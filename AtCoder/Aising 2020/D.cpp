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
	int N; cin >> N;
	string S; cin >> S;
	
	vi pow2H (N);
	vi pow2L (N);
	int base_popcount = 0;
	F0R(i, N) base_popcount += S[i] == '1';
	// todo base_popcount == 1
	int modH = 1;
	int modL = 1;
	F0R(i, N) {
		pow2H[i] = modH;
		pow2L[i] = modL;
		modH = 2 * modH % (base_popcount + 1);
		if (base_popcount > 1) modL = 2 * modL % (base_popcount - 1);
	}

	int valH = 0;
	int valL = 0;
	F0R(i, N) {
		if (S[N-i-1] == '1') {
			valH = (valH + pow2H[i]) % (base_popcount + 1);
			if (base_popcount > 1) valL = (valL + pow2L[i]) % (base_popcount - 1);
		}
	}

	F0R(x, N) {
		if (S[x] == '0') {
			// + 1
			int val = (valH + pow2H[N-x-1]) % (base_popcount + 1);
			int ans = 1;
			while (val != 0) {
				val = val % __builtin_popcount(val);
				++ans;
			}
			print(ans);
		} else {
			// - 1
			if (base_popcount == 1) {
				print(0);
			} else {
				int val = (valL - pow2L[N-x-1] + base_popcount - 1) % (base_popcount - 1);
				int ans = 1;
				while (val != 0) {
					val = val % __builtin_popcount(val);
					++ans;
				}
				print(ans);
			}
		}
	}
}