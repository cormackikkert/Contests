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

const int N = 50;
int dp [N][N][N][4];

bool recurse(int i, int j, int k, int l) {
	if (i == j || j == k || k == i) return false;
	if (dp[i][j][k][l] != -1) return dp[i][j][k][l];
	bool allWin = true;
	for (int f = 0; f < N; ++f) {
		if (l != 0 && i + f < N) allWin &= recurse(i + f, j, k, 0);
		if (l != 1 && j + f < N) allWin &= recurse(i, j + f, k, 1);
		if (l != 2 && k + f < N) allWin &= recurse(i, j, k + f, 2);
	}
	dp[i][j][k][l] = !allWin;
	return !allWin;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	F0R(i, N) F0R(j, N) F0R(k, N) F0R(l, 3) dp[i][j][k][l] = -1;
	F0R(i, N) F0R(j, N) F0R(k, N) if (recurse(i, j, k, 3)) {
		print(i, j, k);
	}
}