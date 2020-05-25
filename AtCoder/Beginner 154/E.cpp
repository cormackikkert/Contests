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

string N;

int dp[100][4][2];

int recurse(int pos, int rem, bool lessthan) {
	if (pos == N.length()) return (rem == 0);
	if (rem == 0) return recurse(pos + 1, rem, lessthan);
	

	if (dp[pos][rem][lessthan] != -1) return dp[pos][rem][lessthan];

	int ans = 0;
	if (lessthan) {
		// use digit
		ans += 9 * recurse(pos + 1, rem - 1, true);
		
		// dont use digit
		ans += recurse(pos + 1, rem, true);
	} else {
		// use digit
		for (int i = 1; i <= 9; ++i) {
			if (i < N[pos] - '0') {
				ans += recurse(pos + 1, rem - 1, true);
			} else if (i == N[pos] - '0') {
				ans += recurse(pos + 1, rem - 1, false);
			}
		}

		// dont use digit
		if (N[pos] == '0') {
			ans += recurse(pos + 1, rem, false);
		} else {
			ans += recurse(pos + 1, rem, true);
		}
	}

	dp[pos][rem][lessthan] = ans;
	return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	int orig_length = N.length();
	for (int i = 0; i < 100 - orig_length; ++i) {
		N = "0" + N;
	}

	int K; cin >> K;

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	
	print(recurse(0, K, false));
}