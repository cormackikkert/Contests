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

const int M = 1e9+10;
int seg [2 * M] = {0};

void displace(int x, int val) {
	seg[x += M] += val;
	for (x /= 2; x; x /= 2) seg[x] = seg[2*x] + seg[2*x+1];
}

int query(int l, int r) {
	int res = 0;
	for (l += M, r += M+1; l < r; l /= 2, r /= 2) {
		if (l&1) res += seg[l++];
		if (r&1) res += seg[--r];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, Q; cin >> N >> Q;
	vi arr (N);
	F0R(i, N) cin >> arr[i];

	F0R(i, N) displace(arr[i], 1);

	F0R(i, Q) {
		char t; cin >> t;
		if (t == '!') {
			int k, x; cin >> k >> x;
			displace(arr[k-1], -1);
			arr[k-1] = x;
			displace(arr[k-1], 1);
		} else {
			int a, b; cin >> a >> b;
			print(query(a, b));
		}
	}
}