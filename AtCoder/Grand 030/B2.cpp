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

ll L, N; 
vll arr;

ll alternate(int cl, int cr, ll cp, bool side) {
	if (cl < cr) return 0;
	if (side) {
		// on right side
		return cp + L - arr[cl] + alternate(cl - 1, cr, arr[cl], false);
	} else {
		// on left side
		return L - cp + arr[cr] + alternate(cl, cr + 1, arr[cr], true);
	}
}

ll calcR(int r) {
	ll ans = 0;
	if (r != 0) {
		ans += arr[r-1];
		ans += alternate(N - 1, r, arr[r-1], true);
	} else {
		ans += L - arr[N-1] + alternate(N-2, 0, arr[N-1], false);
	}
	return ans;
}

ll calcL(int l) {
	ll ans = 0;
	if (l != 0) {
		ans += L - arr[N-l];
		ans += alternate(N-l-1, 0, arr[N-l], false);
	} else {
		ans += arr[0] + alternate(N-1, 1, arr[0], true);
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> L >> N;
	arr.resize(N);
	F0R(i, N) cin >> arr[i];
	F0R(i, N) print(i, calcR(i));
	
	ll cur = calcR(N);
	ll best = calcR(N);
	for (int i = N-3; i >= 0; i -= 2) {
		cur += 2 * (arr[i] + L - arr[i+2]) - (arr[i+2] - arr[i+1]);
		print(cur, calcR(i+1));
	}	// print(max(rBest, lBest));
}