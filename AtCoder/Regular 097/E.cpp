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
	vector<pii> arr (2*N);
	F0R(i, 2*N) {
		char c; cin >> c;
		int a; cin >> a;
		arr[i] = {c == 'B', a};
	}

	vector<vi> wbelow(2*N, vi (N+1));
	F0R(i, 2*N) F0R(j, N+1) {
		wbelow[i][j] = (!arr[i].first) && arr[i].second <= j;
		if (i > 0) wbelow[i][j] += wbelow[i-1][j];
	}
	
	vector<vi> bbelow(2*N, vi (N+1));
	F0R(i, 2*N) F0R(j, N+1) {
		bbelow[i][j] = (arr[i].first) && arr[i].second <= j;
		if (i > 0) bbelow[i][j] += bbelow[i-1][j];
	}

	vi wpos (N+1);
	vi bpos (N+1);
	F0R(i, 2*N) {
		if (arr[i].first) bpos[arr[i].second] = i;
		else wpos[arr[i].second] = i;
	}

	vector<vi> dp (N+1, vi (N+1, 4*N*N));
	dp[0][0] = 0;
	F0R(w, N+1) F0R(b, N+1) {
		if (w == 0 && b == 0) continue;
		if (w > 0) dp[w][b] = min(dp[w][b], dp[w-1][b] + wpos[w] - wbelow[wpos[w]][w-1] - bbelow[wpos[w]][b]);
		if (b > 0) dp[w][b] = min(dp[w][b], dp[w][b-1] + bpos[b] - bbelow[bpos[b]][b-1] - wbelow[bpos[b]][w]);
	}
	print(dp[N][N]);
}