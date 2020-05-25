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
using pll = pair<ll, ll>;


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
		pr("{",x.first,", ",x.second,"}"); 
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

ll N;
vector<pll> arr;
vector<vll> dp;

ll recurse(ll pos, ll lhs) {
	if (pos == N) return 0;
	if (dp[pos][lhs] != -1) return dp[pos][lhs];
	
	ll best = 0;
	best = max(best, arr[pos].first * abs(arr[pos].second - lhs) + recurse(pos + 1, lhs + 1));
	best = max(best, arr[pos].first * abs(arr[pos].second - (N-1-(pos-lhs))) + recurse(pos + 1, lhs));

	dp[pos][lhs] = best;
	return best;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	arr.resize(N); 

	dp = vector<vll> (N + 1, vll (N + 1, -1));
	F0R(i, N) {
		ll x; cin >> x;
		arr[i] = {x, i};
	}

	sort(arr.begin(), arr.end(), [] (const pll lhs, const pll rhs) {
		return lhs.first > rhs.first || (lhs.first == rhs.first && abs(lhs.second - N/2) < abs(rhs.second - N/2));
	});

	print(recurse(0, 0));	
}