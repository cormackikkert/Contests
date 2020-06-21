#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

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
	int N, C; cin >> N >> C;
	vector<pair<pii, int>> data (N);
	F0R(i, N) {
		int a, b; cin >> a >> b;
		data[i] = {{a, b}, i};
	}

	sort(data.begin(), data.end(), [](const auto& lhs, const auto& rhs) {
		return  lhs.f.s - lhs.f.f < rhs.f.s - rhs.f.f;
	});
	
	vector<vector<pii>> dp (N+1, vector<pii> (C+1, {-1, -1}));
	F0R(i, N) {
		F0R(c, C+1) {
			dp[i+1][c] = max(dp[i+1][c], dp[i][c]);
			if (c + max(data[i].f.f, data[i].f.s) <= C) {
				dp[i+1][c + data[i].f.s] = max(dp[i+1][c+data[i].f.s], {1 + dp[i][c].f, i});
			}
		}
	}
	
	vi ans;
	pii best = {-1, -1};
	int ind = -1;
	F0R(i, C+1) if (dp[N][i] > best) {
		best = dp[N][i];
		ind = i;
	}
	int i = N; 
	int s = ind;
	while (s != -1) {
		ans.push_back(data[dp[i][s].s].s);
		i = dp[i][s].s;
		if (i == -1) break;
		s -= data[dp[i][s].s].f.s;
	}
	print(ans.size());
	reverse(ans.begin(), ans.end());
	for (int x : ans) cout << x + 1 << " ";
	cout << endl;
}