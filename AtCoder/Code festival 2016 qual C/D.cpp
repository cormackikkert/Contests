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

int H, W; 
int c1 [305][305];
int c2 [305][305];
int dp [305][305];

int cost(vector<char> s1, vector<char> s2) {
	F0R(i, 305) F0R(j, 305) c1[i][j] = 0, c2[i][j] = 0, dp[i][j] = 1e6;

	// s1 < s2
	F0R(i, H) {
		int total = 0;
		F0R(j, H) if (j + i < H) {
			total += s1[i+j] == s2[j];
			c1[i][j] = total;
		}
	} 

	// s2 < s1
	F0R(j, H) {
		int total = 0;
		F0R(i, H) if (j + i < H) {
			total += s2[i+j] == s1[i];
			c2[j][i] = total;
		}
	}

	F0R(i, H+1) F0R(j, H+1) {
		if (i == 0 || j == 0) dp[i][j] = 0;
		if (j > 0) {
			int movecost = (j > i) ? c1[j-i][i-1] : c2[i-j][j-1];
			dp[i][j] = min(dp[i][j], dp[i][j-1] + movecost);
		}
		if (i > 0) {
			int movecost = (j > i) ? c1[j-i][i-1] : c2[i-j][j-1];
			dp[i][j] = min(dp[i][j], dp[i-1][j] + movecost); 
		}
	}
	return dp[H][H];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> H >> W;
	vector<vector<char>> stacks (W, vector<char> (H));
	F0R(i, H) F0R(j, W) cin >> stacks[j][i];

	int ans = 0;
	F0R(i, W-1) ans += cost(stacks[i], stacks[i+1]);
	print(ans);
}