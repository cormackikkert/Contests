#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = 1LL << 60;

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
	ll N; cin >> N;
	vll arr (N);
	F0R(i, N) cin >> arr[i];
	if (N % 2 == 0) {
		// ez case
		ll m0 = 0;
		ll m1 = 0;
		F0R(i, N) {
			if (i % 2 == 0) 
				m0 += arr[i];
			else 
				m1 += arr[i];
		}
		ll best = max(m0, m1);

		// nah im dumb

		vll lsum (N);
		F0R(i, N) {
			lsum[i] += arr[i];
			if (i - 2 >= 0) lsum[i] += lsum[i-2];
		}
		vll rsum (N);
		R0F(i, N) {
			rsum[i] += arr[i];
			if (i + 2 < N) rsum[i] += rsum[i+2];
		}
		if (N >= 2) {
			for (int i = 1; i + 2 < N; ++i) {
				best = max(best, lsum[i-1] + rsum[i+2]);
			}
		}

		print(best);
	} else {
		vll lsum (N);
		F0R(i, N) {
			lsum[i] += arr[i];
			if (i - 2 >= 0) lsum[i] += lsum[i-2];
		}
		vll rsum (N);
		R0F(i, N) {
			rsum[i] += arr[i];
			if (i + 2 < N) rsum[i] += rsum[i+2];
		}

		ll best = max(rsum[2], lsum[N-3]);
		best = max(best, rsum[1]);
		best = max(best, lsum[N-2]);

		for (int i = 1; i + 2 < N; ++i) {
			best = max(best, lsum[i-1] + rsum[i+2]);
			if (i + 3 < N && (i % 2 == 1)) best = max(best, lsum[i-1] + rsum[i+3]);
		}

		// dp case :D
		vector<vll> dp (3, vll (N, -INF));
		F0R(i, N) {
			// t = 0
			if (i % 2 == 0) dp[0][i] = arr[i];
			if (i - 2 >= 0) dp[0][i] += dp[0][i-2];

			// t = 1
			if ((i % 2 == 1) && (i - 3 >= 0)) {
				dp[1][i] = dp[0][i-3] + arr[i];
				if (i - 5 >= 0) dp[1][i] = max(dp[1][i], dp[1][i-2] + arr[i]);
			}

			// t = 2
			if ((i % 2 == 0) && (i - 6 >= 0)) {
				dp[2][i] = dp[1][i-3] + arr[i];
				if (i - 8 >= 0) dp[2][i] = max(dp[2][i], dp[2][i-2] + arr[i]); 
			}
			// print(i, dp[0][i], dp[1][i], dp[2][i]);
		}
		if (N >= 7) best = max(best, dp[2][N-1]);
		print(best);
	}
}