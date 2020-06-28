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

int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	
	vector<vector<int>> dp (N, vector<int> (M+1));
	
	vi arr (N);
	F0R(i, N) cin >> arr[i];

	if (arr[0] == 0) {
		// not cool bro
		int i = 0;
		while (i < N && arr[i] == 0) ++i; // please have at least one 
		if (i == N) {
			for (int j = 1; j <= M; ++j) dp[0][j] = 1;
		} else {
			for (int j = max(1, arr[i] - i); j <= min(M, arr[i] + i); ++j) dp[0][j] = 1;
		}
	} else {
		dp[0][arr[0]] = 1;
	}

	FOR(i, 1, N) {
		if (arr[i] != 0) {
			for (int j = max(1, arr[i] - 1); j <= min(M, arr[i] + 1); ++j) {
				dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][j]) % MOD;
			}
		} else {
			for (int m = 1; m <= M; ++m) {
				for (int j = max(1, m - 1); j <= min(M, m + 1); ++j) {
					dp[i][m] = (dp[i][m] + dp[i-1][j]) % MOD;
				}
			}
		}
	}

	if (arr[N-1] == 0) {
		int sum = 0;
		FOR(i, 1, M+1) sum = (sum + dp[N-1][i]) % MOD;
		print(sum); 
	} else {
		print(dp[N-1][arr[N-1]]);
	}
}