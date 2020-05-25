#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = 1LL<<60;

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
	
	ll N, K, S; cin >> N >> K >> S;

	// dp[i][j][k][l] = minimum time for k projects getting to i,j (l is transit dir)

	vector<vi> scores (N, vi (N));
	
	F0R(i, N) F0R(j, N) cin >> scores[i][j];

	ll dp[301][601][3];
	ll newdp [301][601][3];

	F0R(j, 301) F0R(k, 601) F0R(l, 3) dp[j][k][l] = INF;
	dp[0][0][2] = 0;
	dp[0][1][2] = scores[0][0];

	int best = 0;
	F0R(i, N) {
		
		F0R(j, 301) F0R(k, 601) F0R(l, 3) newdp[j][k][l] = INF;
		F0R(j, N) F0R(k, N+N) R0F(l, 3) {
			if (l == 0) {
				// currently moving right
				if (j + 1 < N) {
					dp[j+1][k+1][2] = min(dp[j+1][k+1][2], dp[j][k][l] + S + scores[i][j+1]);
					dp[j+1][k][2] = min(dp[j+1][k][2], dp[j][k][l] + S);
					dp[j+1][k][l] = min(dp[j+1][k][l], dp[j][k][l]);
				}
			} else if (l == 1) {
				// currently moving down
				if (i + 1 < N) {
					newdp[j][k+1][2] = min(newdp[j][k+1][2], dp[j][k][l] + S + scores[i+1][j]);
					newdp[j][k][2] = min(newdp[j][k][2], dp[j][k][l] + S);
					newdp[j][k][l] = min(newdp[j][k][l], dp[j][k][l]);
				}
			} else {
				// at a city
				dp[j][k][0] = min(dp[j][k][0], dp[j][k][l]);
				dp[j][k][1] = min(dp[j][k][1], dp[j][k][l]);
			}
			if (dp[j][k][l] <= K) best = max(best, k);
		}
		memcpy(dp, newdp, 301*601*3*sizeof(ll));
	}
	print(best);
}