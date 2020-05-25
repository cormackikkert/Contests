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
	ll K; cin >> K;
	vector<vll> dp (100, vll (10));
	F0R(i, 10) dp[0][i] = 1;
	FOR(i, 1, 100) {
		F0R(j, 10) {
			dp[i][j] += dp[i-1][j];
			if (j - 1 >= 0) dp[i][j] += dp[i-1][j-1];
			if (j + 1 < 10) dp[i][j] += dp[i-1][j+1];
		}
	}

	
	int ai = 100;
	int aj = 100;
	ll total = 0;
	ll gay = 0;
	F0R(i, 100) {
		F0R(j, 10) {
			total += dp[i][j];
			if (j == 0) K += dp[i][j];
			if (K <= total) {
				ai = i;
				aj = j;
				i = 100;
				j = 10;
			}
			// if (j == 0) total += dp[i][j];
		}
	}
	// print(ai, aj);
	// print(lt[0]);
	// print(lt[1]);
	K = total - K;
	string ans = "";
	while (ai >= 0) {
		// print(ai, aj);
		ans += to_string(aj);
		if (ai == 0) break;
		
		if (aj + 1 < 10 && dp[ai-1][aj+1] > K) {
			aj = aj + 1;
		} else {
			if (aj + 1 < 10) K -= dp[ai-1][aj+1];
			if (dp[ai-1][aj] > K) {
				aj = aj;
			} else {
				K -= dp[ai-1][aj];
				aj = aj - 1;
			}
		}
		--ai;
	}
	print(ans);
}