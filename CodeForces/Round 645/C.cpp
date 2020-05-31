#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

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

ll tri(ll n) {
	if (n <= 0) return 0;
	return n * (n + 1) * (n + 2) / 6;
}

ll get_cell(ll x, ll y) {
	ll rows = (x - 1) + (y - 1);
	ll ans = rows * (rows + 1) / 2;
	ans += y;
	return ans;
}

ll get_row(ll x, ll y) {
	return x * (get_cell(1, y) + get_cell(1, y) + (x - 1) * y) / 2LL + tri(x - 2);
}

ll get_col(ll x, ll y) {
	return y * (get_cell(x, 1) + get_cell(x, 1) + (y - 1) * x) / 2LL + tri(y - 1);
}

ll get_strip_x(ll h, ll x1, ll x2) {
	return get_row(h, x2) - get_row(h, x1-1);
}

ll get_strip_y(ll x, ll y1, ll y2) {
	return get_col(x, y2) - get_col(x, y1-1);
}

void solve() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	ll hi = get_strip_y(x1, y1, y2) + get_strip_x(y2, x1, x2) - get_cell(x1, y2);
	ll lo = get_strip_x(y1, x1, x2) + get_strip_y(x2, y1, y2) - get_cell(x2, y1);
	print(hi - lo + 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	F0R(i, T) solve();
}