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

ll dp [50*50+1][51];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, A; cin >> N >> A;
	vi arr (N);
	F0R(i, N) cin >> arr[i];
	sort(arr.begin(), arr.end());
	dp[arr[0]][1] = 1;
	dp[0][0] = 1;

	FOR(i, 1, N) {
		R0F(c, N) {
			R0F(s, 50 * 50 + 1) {
				// if (s + arr[i] == 24) print("ADDING", i, c, dp[s][c]);
				if (s + arr[i] <= 50 * 50) dp[s + arr[i]][c+1] += dp[s][c];
			}
		}
	}

	ll ans = 0;
	FOR(i, 1, N+1) {
		// print(i, dp[A*i][i]);
		ans += dp[A*i][i];
	}
	print(ans);
	// print(dp[24-9]);
	// print(dp[24]);
}