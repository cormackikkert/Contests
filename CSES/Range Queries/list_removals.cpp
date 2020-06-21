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

struct Seg {
	int N;
	vll seg;

	void init(int N_) {
		N = N_;
		seg = vll (2*N);
	}

	void update(int x, ll val) {
		seg[x += N] = val;
		for (x /= 2; x; x /= 2) seg[x] = seg[2*x] + seg[2*x+1];
	}

	ll query(int l, int r) {
		ll res = 0;
		for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
			if (l&1) res += seg[l++];
			if (r&1) res += seg[--r];
		}
		return res;
	}

	int getIndex(int pos) {
		int cur = 1;
		while (cur < N) {
			if (seg[2*cur] >= pos) cur = 2 * cur;
			else {
				pos -= seg[2*cur];
				cur = 2 * cur + 1;
			}
		}
		return cur - N;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	Seg seg; seg.init(1 << 18);
	vi orig (N);

	F0R(i, N) {
		int val; cin >> val;
		seg.update(i, 1);
		orig[i] = val;
	}

	F0R(i, N) {
		int d; cin >> d;
		int ind = seg.getIndex(d);
		// print(ind);
		cout << orig[ind] << " ";
		seg.update(ind, 0);
	}
	cout << endl;
}